/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tnet.h
 * @brief Protocol agnostic socket.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */

#include "tnet_socket.h"

#include "tnet_utils.h"

#include "tsk_string.h"
#include "tsk_debug.h"

#include <string.h>

/**
 * @fn	int tnet_socket_close(const tnet_socket_t *socket)
 *
 * @brief	Closes a socket. 
 *
 * @author	Mamadou
 * @date	12/11/2009
 *
 * @param [in]	sock	If non-null, the socket. 
 *
 * @return	Zero if succeed and nonzero error code otherwise. 
**/
int tnet_socket_close(tnet_socket_t *sock)
{
	return tnet_sockfd_close(&(sock->fd));	
}


int tnet_socket_stream_connectto(tnet_socket_tcp_t *sock, const char* host, tnet_port_t port)
{
	int status = 0;
	tsk_istr_t _port;
	struct addrinfo *result = 0;
	struct addrinfo *ptr = 0;
	struct addrinfo hints;

	if(!TNET_SOCKET_IS_VALID(sock))
	{
		TSK_DEBUG_ERROR("Could not connect invalid socket.");
		return -1;
	}

	tsk_itoa(port, &_port);

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = TNET_SOCKET_TYPE_IS_IPV6(sock->type) ? AF_INET6 : AF_INET;
	hints.ai_socktype = TNET_SOCKET_TYPE_IS_STREAM(sock->type) ? SOCK_STREAM : SOCK_DGRAM;
	hints.ai_protocol = TNET_SOCKET_TYPE_IS_STREAM(sock->type) ? IPPROTO_TCP : IPPROTO_UDP;

	
	if((status = tnet_getaddrinfo(host, _port, &hints, &result)))
	{
		TNET_PRINT_LAST_ERROR("getaddrinfo have failed.");
		goto bail;
	}

	for(ptr = result; ptr; ptr = ptr->ai_next) 
	{
		if(ptr->ai_family == hints.ai_family && ptr->ai_socktype == hints.ai_socktype && ptr->ai_protocol == hints.ai_protocol)
		{
			if((status = connect(sock->fd, ptr->ai_addr, ptr->ai_addrlen)))
			{
				TNET_PRINT_LAST_ERROR("connect have failed.");
				goto bail;
			}

			TSK_DEBUG_INFO("Successfuly connected to: %s on port %d\n", host, port);
			break;
		}
	}

bail:
	tnet_freeaddrinfo(result);
	return status;
}


int tnet_socket_sendto(tnet_socket_t *socket, const struct sockaddr *to, const void* buf, size_t size)
{
	if(socket)
	{
		return tnet_sockfd_sendto(socket->fd, to, buf, size);
	}
	return -1;
}




//=================================================================================================
//	SOCKET object definition
//
static void* tnet_socket_create(void * self, va_list * app)
{
	tnet_socket_t *sock = self;
	if(sock)
	{
		int status;
		int nonblocking;
		tsk_istr_t port;
		struct addrinfo *result = 0;
		struct addrinfo *ptr = 0;
		struct addrinfo hints;
		tnet_host_t local_hostname;

		const char *host = va_arg(*app, const char*);
#if defined(__GNUC__)
		sock->port = (tnet_port_t)va_arg(*app, unsigned);
#else
		sock->port = va_arg(*app, tnet_port_t);
#endif
		tsk_itoa(sock->port, &port);
		sock->type = va_arg(*app, tnet_socket_type_t);
		nonblocking = va_arg(*app, int);

		/* Get the local host name */
		if(host != TNET_SOCKET_HOST_ANY && !tsk_strempty(host))
		{
			memset(local_hostname, 0, sizeof(local_hostname));
			memcpy(local_hostname, host, strlen(host)>sizeof(local_hostname)-1 ? sizeof(local_hostname)-1 : strlen(host));
		}
		else
		{
			if((status = tnet_gethostname(&local_hostname)))
			{
				TNET_PRINT_LAST_ERROR("gethostname have failed.");
				goto bail;
			}
		}

		/* hints address info structure */
		memset(&hints, 0, sizeof(hints));
		hints.ai_family = TNET_SOCKET_TYPE_IS_IPV6(sock->type) ? AF_INET6 : AF_INET;
		hints.ai_socktype = TNET_SOCKET_TYPE_IS_STREAM(sock->type) ? SOCK_STREAM : SOCK_DGRAM;
		hints.ai_protocol = TNET_SOCKET_TYPE_IS_STREAM(sock->type) ? IPPROTO_TCP : IPPROTO_UDP;
		hints.ai_flags = AI_PASSIVE
#if !TNET_UNDER_WINDOWS
			| AI_ADDRCONFIG
#endif
			;

		/* Performs getaddrinfo */
		if((status = tnet_getaddrinfo(local_hostname, port, &hints, &result)))
		{
			TNET_PRINT_LAST_ERROR("getaddrinfo have failed.");
			goto bail;
		}
		
		/* Find our address. */
		for(ptr = result; ptr; ptr = ptr->ai_next)
		{
			//if(ptr->ai_family == hints.ai_family && ptr->ai_socktype == hints.ai_socktype && ptr->ai_protocol == hints.ai_protocol)
			{
				sock->fd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
				
				/* Bind the socket */
				if((status = bind(sock->fd, ptr->ai_addr, ptr->ai_addrlen)))
				{
					TNET_PRINT_LAST_ERROR("bind have failed.");
					tnet_socket_close(sock);
					continue;
				}

				/* Get local IP string. */
				if(status = tnet_get_ip_n_port(sock->fd , &sock->ip, &sock->port)) /* % */
				//if((status = tnet_getnameinfo(ptr->ai_addr, ptr->ai_addrlen, sock->ip, sizeof(sock->ip), 0, 0, NI_NUMERICHOST)))
				{
					TNET_PRINT_LAST_ERROR("Failed to get local IP and port.");
					tnet_socket_close(sock);
					continue;
				}
			}
		}
		
		/* Check socket validity. */
		if(!TNET_SOCKET_IS_VALID(sock)) 
		{
			TNET_PRINT_LAST_ERROR("Invalid socket.");
			goto bail;
		}		

		/* To avoid "Address already in use" error */
		{
#if defined(SOLARIS)
			char yes = '1';
#else
			int yes = 1;
#endif
			if(setsockopt(sock->fd, SOL_SOCKET, SO_REUSEADDR, (char*)&yes, sizeof(int)))
			{
				TNET_PRINT_LAST_ERROR("setsockopt(SO_REUSEADDR) have failed.");
			}
		}

		/* Sets the socket to nonblocking mode */
		if(nonblocking)
		{
			if((status = tnet_sockfd_set_nonblocking(sock->fd)))
			{
				goto bail;
			}
		}

bail:
		/* Free addrinfo */
		tnet_freeaddrinfo(result);

		/* Close socket if failed. */
		if(status)
		{
			tnet_socket_close(sock);
		}

	}
	return self;
}

static void* tnet_socket_destroy(void * self)
{ 
	tnet_socket_t *sock = self;
	if(sock && sock->fd > 0)
	{
		/* Close the socket. */
		tnet_socket_close(sock);
	}

	return self;
}

static const tsk_object_def_t tnet_socket_def_s = 
{
	sizeof(tnet_socket_t),
	tnet_socket_create, 
	tnet_socket_destroy,
	0, 
};
const void *tnet_socket_def_t = &tnet_socket_def_s;


