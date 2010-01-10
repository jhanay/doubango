/*
 * ex: set ro:
 * DO NOT EDIT.
 * generated by smc (http://smc.sourceforge.net/)
 * from file : tsip_dialog_register.sm
 */


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
* GNU Lesser General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tsip_dialog_register.sm.
 * @brief SIP dialog REGISTER.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */

//#define tsip_dialog_register_TSIP_DIALOG_BEGIN_TRANSIT(self)	TSIP_DIALOG_BEGIN_TRANSIT(self)
//#define tsip_dialog_register_TSIP_DIALOG_END_TRANSIT(self)		TSIP_DIALOG_END_TRANSIT(self)


#include <assert.h>
#include "tinysip/dialogs/tsip_dialog_register.h"
#include "tsk_debug.h"
#include "tinysip/smc/tsip_dialog_register_sm.h"

#define getOwner(fsm) \
    (fsm)->_owner

#define POPULATE_STATE(state) \
    state##_Entry, \
    state##_sm_1xx, \
    state##_sm_2xx, \
    state##_sm_300_to_699, \
    state##_sm_401_407_421_494, \
    state##_sm_423, \
    state##_sm_cancel, \
    state##_sm_error, \
    state##_sm_hangup, \
    state##_sm_refresh, \
    state##_sm_send, \
    state##_sm_transportError, \
    state##_sm_unregister, \
    state##_Default

#define ENTRY_STATE(state) \
    if ((state)->Entry != NULL) { \
        (state)->Entry(fsm); \
    }

#define EXIT_STATE(state)

static void tsip_dialog_registerState_sm_1xx(struct tsip_dialog_registerContext *fsm, const tsip_message_t* msg)
{
    getState(fsm)->Default(fsm);
}

static void tsip_dialog_registerState_sm_2xx(struct tsip_dialog_registerContext *fsm, int unregistering, const tsip_message_t* msg)
{
    getState(fsm)->Default(fsm);
}

static void tsip_dialog_registerState_sm_300_to_699(struct tsip_dialog_registerContext *fsm, const tsip_message_t* msg)
{
    getState(fsm)->Default(fsm);
}

static void tsip_dialog_registerState_sm_401_407_421_494(struct tsip_dialog_registerContext *fsm, const tsip_message_t* msg)
{
    getState(fsm)->Default(fsm);
}

static void tsip_dialog_registerState_sm_423(struct tsip_dialog_registerContext *fsm, const tsip_message_t* msg)
{
    getState(fsm)->Default(fsm);
}

static void tsip_dialog_registerState_sm_cancel(struct tsip_dialog_registerContext *fsm)
{
    getState(fsm)->Default(fsm);
}

static void tsip_dialog_registerState_sm_error(struct tsip_dialog_registerContext *fsm)
{
    getState(fsm)->Default(fsm);
}

static void tsip_dialog_registerState_sm_hangup(struct tsip_dialog_registerContext *fsm)
{
    getState(fsm)->Default(fsm);
}

static void tsip_dialog_registerState_sm_refresh(struct tsip_dialog_registerContext *fsm)
{
    getState(fsm)->Default(fsm);
}

static void tsip_dialog_registerState_sm_send(struct tsip_dialog_registerContext *fsm)
{
    getState(fsm)->Default(fsm);
}

static void tsip_dialog_registerState_sm_transportError(struct tsip_dialog_registerContext *fsm)
{
    getState(fsm)->Default(fsm);
}

static void tsip_dialog_registerState_sm_unregister(struct tsip_dialog_registerContext *fsm)
{
    getState(fsm)->Default(fsm);
}

static void tsip_dialog_registerState_Default(struct tsip_dialog_registerContext *fsm)
{
    State_Default(fsm);
}

#define tsip_dialog_register_Started_sm_1xx tsip_dialog_registerState_sm_1xx
#define tsip_dialog_register_Started_sm_2xx tsip_dialog_registerState_sm_2xx
#define tsip_dialog_register_Started_sm_300_to_699 tsip_dialog_registerState_sm_300_to_699
#define tsip_dialog_register_Started_sm_401_407_421_494 tsip_dialog_registerState_sm_401_407_421_494
#define tsip_dialog_register_Started_sm_423 tsip_dialog_registerState_sm_423
#define tsip_dialog_register_Started_sm_cancel tsip_dialog_registerState_sm_cancel
#define tsip_dialog_register_Started_sm_error tsip_dialog_registerState_sm_error
#define tsip_dialog_register_Started_sm_hangup tsip_dialog_registerState_sm_hangup
#define tsip_dialog_register_Started_sm_refresh tsip_dialog_registerState_sm_refresh
#define tsip_dialog_register_Started_sm_send tsip_dialog_registerState_sm_send
#define tsip_dialog_register_Started_sm_transportError tsip_dialog_registerState_sm_transportError
#define tsip_dialog_register_Started_sm_unregister tsip_dialog_registerState_sm_unregister
#define tsip_dialog_register_Started_Default tsip_dialog_registerState_Default
#define tsip_dialog_register_Started_Entry NULL
#define tsip_dialog_register_Started_Exit NULL
#define tsip_dialog_register_Trying_sm_1xx tsip_dialog_registerState_sm_1xx
#define tsip_dialog_register_Trying_sm_2xx tsip_dialog_registerState_sm_2xx
#define tsip_dialog_register_Trying_sm_300_to_699 tsip_dialog_registerState_sm_300_to_699
#define tsip_dialog_register_Trying_sm_401_407_421_494 tsip_dialog_registerState_sm_401_407_421_494
#define tsip_dialog_register_Trying_sm_423 tsip_dialog_registerState_sm_423
#define tsip_dialog_register_Trying_sm_cancel tsip_dialog_registerState_sm_cancel
#define tsip_dialog_register_Trying_sm_error tsip_dialog_registerState_sm_error
#define tsip_dialog_register_Trying_sm_hangup tsip_dialog_registerState_sm_hangup
#define tsip_dialog_register_Trying_sm_refresh tsip_dialog_registerState_sm_refresh
#define tsip_dialog_register_Trying_sm_send tsip_dialog_registerState_sm_send
#define tsip_dialog_register_Trying_sm_transportError tsip_dialog_registerState_sm_transportError
#define tsip_dialog_register_Trying_sm_unregister tsip_dialog_registerState_sm_unregister
#define tsip_dialog_register_Trying_Default tsip_dialog_registerState_Default
#define tsip_dialog_register_Trying_Entry NULL
#define tsip_dialog_register_Trying_Exit NULL
#define tsip_dialog_register_Connected_sm_1xx tsip_dialog_registerState_sm_1xx
#define tsip_dialog_register_Connected_sm_2xx tsip_dialog_registerState_sm_2xx
#define tsip_dialog_register_Connected_sm_300_to_699 tsip_dialog_registerState_sm_300_to_699
#define tsip_dialog_register_Connected_sm_401_407_421_494 tsip_dialog_registerState_sm_401_407_421_494
#define tsip_dialog_register_Connected_sm_423 tsip_dialog_registerState_sm_423
#define tsip_dialog_register_Connected_sm_cancel tsip_dialog_registerState_sm_cancel
#define tsip_dialog_register_Connected_sm_error tsip_dialog_registerState_sm_error
#define tsip_dialog_register_Connected_sm_hangup tsip_dialog_registerState_sm_hangup
#define tsip_dialog_register_Connected_sm_refresh tsip_dialog_registerState_sm_refresh
#define tsip_dialog_register_Connected_sm_send tsip_dialog_registerState_sm_send
#define tsip_dialog_register_Connected_sm_transportError tsip_dialog_registerState_sm_transportError
#define tsip_dialog_register_Connected_sm_unregister tsip_dialog_registerState_sm_unregister
#define tsip_dialog_register_Connected_Default tsip_dialog_registerState_Default
#define tsip_dialog_register_Connected_Entry NULL
#define tsip_dialog_register_Connected_Exit NULL
#define tsip_dialog_register_Terminated_sm_1xx tsip_dialog_registerState_sm_1xx
#define tsip_dialog_register_Terminated_sm_2xx tsip_dialog_registerState_sm_2xx
#define tsip_dialog_register_Terminated_sm_300_to_699 tsip_dialog_registerState_sm_300_to_699
#define tsip_dialog_register_Terminated_sm_401_407_421_494 tsip_dialog_registerState_sm_401_407_421_494
#define tsip_dialog_register_Terminated_sm_423 tsip_dialog_registerState_sm_423
#define tsip_dialog_register_Terminated_sm_cancel tsip_dialog_registerState_sm_cancel
#define tsip_dialog_register_Terminated_sm_error tsip_dialog_registerState_sm_error
#define tsip_dialog_register_Terminated_sm_hangup tsip_dialog_registerState_sm_hangup
#define tsip_dialog_register_Terminated_sm_refresh tsip_dialog_registerState_sm_refresh
#define tsip_dialog_register_Terminated_sm_send tsip_dialog_registerState_sm_send
#define tsip_dialog_register_Terminated_sm_transportError tsip_dialog_registerState_sm_transportError
#define tsip_dialog_register_Terminated_sm_unregister tsip_dialog_registerState_sm_unregister
#define tsip_dialog_register_Terminated_Default tsip_dialog_registerState_Default
#define tsip_dialog_register_Terminated_Entry NULL
#define tsip_dialog_register_Terminated_Exit NULL
#define tsip_dialog_register_DefaultState_sm_1xx tsip_dialog_registerState_sm_1xx
#define tsip_dialog_register_DefaultState_sm_2xx tsip_dialog_registerState_sm_2xx
#define tsip_dialog_register_DefaultState_sm_300_to_699 tsip_dialog_registerState_sm_300_to_699
#define tsip_dialog_register_DefaultState_sm_401_407_421_494 tsip_dialog_registerState_sm_401_407_421_494
#define tsip_dialog_register_DefaultState_sm_423 tsip_dialog_registerState_sm_423
#define tsip_dialog_register_DefaultState_sm_cancel tsip_dialog_registerState_sm_cancel
#define tsip_dialog_register_DefaultState_sm_error tsip_dialog_registerState_sm_error
#define tsip_dialog_register_DefaultState_sm_hangup tsip_dialog_registerState_sm_hangup
#define tsip_dialog_register_DefaultState_sm_refresh tsip_dialog_registerState_sm_refresh
#define tsip_dialog_register_DefaultState_sm_send tsip_dialog_registerState_sm_send
#define tsip_dialog_register_DefaultState_sm_transportError tsip_dialog_registerState_sm_transportError
#define tsip_dialog_register_DefaultState_sm_unregister tsip_dialog_registerState_sm_unregister

#undef tsip_dialog_register_Started_sm_hangup
#define tsip_dialog_register_Started_sm_hangup tsip_dialog_register_DefaultState_sm_hangup
#undef tsip_dialog_register_Trying_sm_hangup
#define tsip_dialog_register_Trying_sm_hangup tsip_dialog_register_DefaultState_sm_hangup
#undef tsip_dialog_register_Connected_sm_hangup
#define tsip_dialog_register_Connected_sm_hangup tsip_dialog_register_DefaultState_sm_hangup
#undef tsip_dialog_register_Terminated_sm_hangup
#define tsip_dialog_register_Terminated_sm_hangup tsip_dialog_register_DefaultState_sm_hangup
#undef tsip_dialog_register_DefaultState_sm_hangup
static void tsip_dialog_register_DefaultState_sm_hangup(struct tsip_dialog_registerContext *fsm)
{
    struct tsip_dialog_register* ctxt = getOwner(fsm);

    EXIT_STATE(getState(fsm));
    clearState(fsm);
    tsip_dialog_register_Any_2_Trying_X_hangup(ctxt);
    setState(fsm, &tsip_dialog_register_Trying);
    ENTRY_STATE(getState(fsm));
}

#undef tsip_dialog_register_Started_sm_transportError
#define tsip_dialog_register_Started_sm_transportError tsip_dialog_register_DefaultState_sm_transportError
#undef tsip_dialog_register_Trying_sm_transportError
#define tsip_dialog_register_Trying_sm_transportError tsip_dialog_register_DefaultState_sm_transportError
#undef tsip_dialog_register_Connected_sm_transportError
#define tsip_dialog_register_Connected_sm_transportError tsip_dialog_register_DefaultState_sm_transportError
#undef tsip_dialog_register_Terminated_sm_transportError
#define tsip_dialog_register_Terminated_sm_transportError tsip_dialog_register_DefaultState_sm_transportError
#undef tsip_dialog_register_DefaultState_sm_transportError
static void tsip_dialog_register_DefaultState_sm_transportError(struct tsip_dialog_registerContext *fsm)
{
    struct tsip_dialog_register* ctxt = getOwner(fsm);

    EXIT_STATE(getState(fsm));
    clearState(fsm);
    tsip_dialog_register_Any_2_Terminated_X_transportError(ctxt);
    setState(fsm, &tsip_dialog_register_Terminated);
    ENTRY_STATE(getState(fsm));
}

#undef tsip_dialog_register_Started_sm_error
#define tsip_dialog_register_Started_sm_error tsip_dialog_register_DefaultState_sm_error
#undef tsip_dialog_register_Trying_sm_error
#define tsip_dialog_register_Trying_sm_error tsip_dialog_register_DefaultState_sm_error
#undef tsip_dialog_register_Connected_sm_error
#define tsip_dialog_register_Connected_sm_error tsip_dialog_register_DefaultState_sm_error
#undef tsip_dialog_register_Terminated_sm_error
#define tsip_dialog_register_Terminated_sm_error tsip_dialog_register_DefaultState_sm_error
#undef tsip_dialog_register_DefaultState_sm_error
static void tsip_dialog_register_DefaultState_sm_error(struct tsip_dialog_registerContext *fsm)
{

    EXIT_STATE(getState(fsm));
    setState(fsm, &tsip_dialog_register_Terminated);
    ENTRY_STATE(getState(fsm));
}

#undef tsip_dialog_register_Started_Default
#define tsip_dialog_register_Started_Default tsip_dialog_register_DefaultState_Default
#undef tsip_dialog_register_Trying_Default
#define tsip_dialog_register_Trying_Default tsip_dialog_register_DefaultState_Default
#undef tsip_dialog_register_Connected_Default
#define tsip_dialog_register_Connected_Default tsip_dialog_register_DefaultState_Default
#undef tsip_dialog_register_Terminated_Default
#define tsip_dialog_register_Terminated_Default tsip_dialog_register_DefaultState_Default
#undef tsip_dialog_register_DefaultState_Default
static void tsip_dialog_register_DefaultState_Default(struct tsip_dialog_registerContext *fsm)
{

}

#undef tsip_dialog_register_Started_Default
static void tsip_dialog_register_Started_Default(struct tsip_dialog_registerContext *fsm)
{

}

#undef tsip_dialog_register_Started_sm_send
static void tsip_dialog_register_Started_sm_send(struct tsip_dialog_registerContext *fsm)
{
    struct tsip_dialog_register* ctxt = getOwner(fsm);

    EXIT_STATE(getState(fsm));
    clearState(fsm);
    tsip_dialog_register_Started_2_Trying_X_send(ctxt);
    setState(fsm, &tsip_dialog_register_Trying);
    ENTRY_STATE(getState(fsm));
}

const struct tsip_dialog_registerState tsip_dialog_register_Started = { POPULATE_STATE(tsip_dialog_register_Started), "tsip_dialog_register_Started", 0 };

#undef tsip_dialog_register_Trying_Default
static void tsip_dialog_register_Trying_Default(struct tsip_dialog_registerContext *fsm)
{

}

#undef tsip_dialog_register_Trying_sm_1xx
static void tsip_dialog_register_Trying_sm_1xx(struct tsip_dialog_registerContext *fsm, const tsip_message_t* msg)
{
    struct tsip_dialog_register* ctxt = getOwner(fsm);
    const struct tsip_dialog_registerState* EndStateName = getState(fsm);

    clearState(fsm);
    tsip_dialog_register_Trying_2_Trying_X_1xx(ctxt, msg);
    setState(fsm, EndStateName);
}

#undef tsip_dialog_register_Trying_sm_2xx
static void tsip_dialog_register_Trying_sm_2xx(struct tsip_dialog_registerContext *fsm, int unregistering, const tsip_message_t* msg)
{
    struct tsip_dialog_register* ctxt = getOwner(fsm);

    if (!unregistering) {
        EXIT_STATE(getState(fsm));
        clearState(fsm);
        tsip_dialog_register_Trying_2_Connected_X_2xx(ctxt, msg);
        setState(fsm, &tsip_dialog_register_Connected);
        ENTRY_STATE(getState(fsm));
    }
    else if (unregistering) {
        EXIT_STATE(getState(fsm));
        clearState(fsm);
        tsip_dialog_register_Trying_2_Terminated_X_2xx(ctxt, msg);
        setState(fsm, &tsip_dialog_register_Terminated);
        ENTRY_STATE(getState(fsm));
    }    else {
        tsip_dialog_register_DefaultState_sm_2xx(fsm, unregistering, msg);
    }
}

#undef tsip_dialog_register_Trying_sm_300_to_699
static void tsip_dialog_register_Trying_sm_300_to_699(struct tsip_dialog_registerContext *fsm, const tsip_message_t* msg)
{
    struct tsip_dialog_register* ctxt = getOwner(fsm);

    EXIT_STATE(getState(fsm));
    clearState(fsm);
    tsip_dialog_register_Trying_2_Terminated_X_300_to_699(ctxt, msg);
    setState(fsm, &tsip_dialog_register_Terminated);
    ENTRY_STATE(getState(fsm));
}

#undef tsip_dialog_register_Trying_sm_401_407_421_494
static void tsip_dialog_register_Trying_sm_401_407_421_494(struct tsip_dialog_registerContext *fsm, const tsip_message_t* msg)
{
    struct tsip_dialog_register* ctxt = getOwner(fsm);
    const struct tsip_dialog_registerState* EndStateName = getState(fsm);

    clearState(fsm);
    tsip_dialog_register_Trying_2_Trying_X_401_407_421_494(ctxt, msg);
    setState(fsm, EndStateName);
}

#undef tsip_dialog_register_Trying_sm_423
static void tsip_dialog_register_Trying_sm_423(struct tsip_dialog_registerContext *fsm, const tsip_message_t* msg)
{
    struct tsip_dialog_register* ctxt = getOwner(fsm);
    const struct tsip_dialog_registerState* EndStateName = getState(fsm);

    clearState(fsm);
    tsip_dialog_register_Trying_2_Trying_X_423(ctxt, msg);
    setState(fsm, EndStateName);
}

#undef tsip_dialog_register_Trying_sm_cancel
static void tsip_dialog_register_Trying_sm_cancel(struct tsip_dialog_registerContext *fsm)
{
    struct tsip_dialog_register* ctxt = getOwner(fsm);

    EXIT_STATE(getState(fsm));
    clearState(fsm);
    tsip_dialog_register_Trying_2_Terminated_X_cancel(ctxt);
    setState(fsm, &tsip_dialog_register_Terminated);
    ENTRY_STATE(getState(fsm));
}

const struct tsip_dialog_registerState tsip_dialog_register_Trying = { POPULATE_STATE(tsip_dialog_register_Trying), "tsip_dialog_register_Trying", 1 };

#undef tsip_dialog_register_Connected_Default
static void tsip_dialog_register_Connected_Default(struct tsip_dialog_registerContext *fsm)
{

}

#undef tsip_dialog_register_Connected_sm_refresh
static void tsip_dialog_register_Connected_sm_refresh(struct tsip_dialog_registerContext *fsm)
{
    struct tsip_dialog_register* ctxt = getOwner(fsm);

    EXIT_STATE(getState(fsm));
    clearState(fsm);
    tsip_dialog_register_Connected_2_Trying_X_refresh(ctxt);
    setState(fsm, &tsip_dialog_register_Trying);
    ENTRY_STATE(getState(fsm));
}

#undef tsip_dialog_register_Connected_sm_unregister
static void tsip_dialog_register_Connected_sm_unregister(struct tsip_dialog_registerContext *fsm)
{
    struct tsip_dialog_register* ctxt = getOwner(fsm);

    EXIT_STATE(getState(fsm));
    clearState(fsm);
    tsip_dialog_register_Connected_2_Trying_X_unregister(ctxt);
    setState(fsm, &tsip_dialog_register_Trying);
    ENTRY_STATE(getState(fsm));
}

const struct tsip_dialog_registerState tsip_dialog_register_Connected = { POPULATE_STATE(tsip_dialog_register_Connected), "tsip_dialog_register_Connected", 2 };

#undef tsip_dialog_register_Terminated_Entry
void tsip_dialog_register_Terminated_Entry(struct tsip_dialog_registerContext *fsm)
{
    struct tsip_dialog_register *ctxt = getOwner(fsm);

    tsip_dialog_register_OnTerminated(ctxt);
}

#undef tsip_dialog_register_Terminated_Default
static void tsip_dialog_register_Terminated_Default(struct tsip_dialog_registerContext *fsm)
{

}

const struct tsip_dialog_registerState tsip_dialog_register_Terminated = { POPULATE_STATE(tsip_dialog_register_Terminated), "tsip_dialog_register_Terminated", 3 };

void tsip_dialog_registerContext_Init(struct tsip_dialog_registerContext* fsm, struct tsip_dialog_register* owner)
{
    FSM_INIT(fsm, &tsip_dialog_register_Started);
    fsm->_owner = owner;
}

void tsip_dialog_registerContext_EnterStartState(struct tsip_dialog_registerContext* fsm)
{
    ENTRY_STATE(getState(fsm));
}

void tsip_dialog_registerContext_sm_1xx(struct tsip_dialog_registerContext* fsm, const tsip_message_t* msg)
{
    const struct tsip_dialog_registerState* state = getState(fsm);

    assert(state != NULL);
    setTransition(fsm, "sm_1xx");
    state->sm_1xx(fsm, msg);
    setTransition(fsm, NULL);
}

void tsip_dialog_registerContext_sm_2xx(struct tsip_dialog_registerContext* fsm, int unregistering, const tsip_message_t* msg)
{
    const struct tsip_dialog_registerState* state = getState(fsm);

    assert(state != NULL);
    setTransition(fsm, "sm_2xx");
    state->sm_2xx(fsm, unregistering, msg);
    setTransition(fsm, NULL);
}

void tsip_dialog_registerContext_sm_300_to_699(struct tsip_dialog_registerContext* fsm, const tsip_message_t* msg)
{
    const struct tsip_dialog_registerState* state = getState(fsm);

    assert(state != NULL);
    setTransition(fsm, "sm_300_to_699");
    state->sm_300_to_699(fsm, msg);
    setTransition(fsm, NULL);
}

void tsip_dialog_registerContext_sm_401_407_421_494(struct tsip_dialog_registerContext* fsm, const tsip_message_t* msg)
{
    const struct tsip_dialog_registerState* state = getState(fsm);

    assert(state != NULL);
    setTransition(fsm, "sm_401_407_421_494");
    state->sm_401_407_421_494(fsm, msg);
    setTransition(fsm, NULL);
}

void tsip_dialog_registerContext_sm_423(struct tsip_dialog_registerContext* fsm, const tsip_message_t* msg)
{
    const struct tsip_dialog_registerState* state = getState(fsm);

    assert(state != NULL);
    setTransition(fsm, "sm_423");
    state->sm_423(fsm, msg);
    setTransition(fsm, NULL);
}

void tsip_dialog_registerContext_sm_cancel(struct tsip_dialog_registerContext* fsm)
{
    const struct tsip_dialog_registerState* state = getState(fsm);

    assert(state != NULL);
    setTransition(fsm, "sm_cancel");
    state->sm_cancel(fsm);
    setTransition(fsm, NULL);
}

void tsip_dialog_registerContext_sm_error(struct tsip_dialog_registerContext* fsm)
{
    const struct tsip_dialog_registerState* state = getState(fsm);

    assert(state != NULL);
    setTransition(fsm, "sm_error");
    state->sm_error(fsm);
    setTransition(fsm, NULL);
}

void tsip_dialog_registerContext_sm_hangup(struct tsip_dialog_registerContext* fsm)
{
    const struct tsip_dialog_registerState* state = getState(fsm);

    assert(state != NULL);
    setTransition(fsm, "sm_hangup");
    state->sm_hangup(fsm);
    setTransition(fsm, NULL);
}

void tsip_dialog_registerContext_sm_refresh(struct tsip_dialog_registerContext* fsm)
{
    const struct tsip_dialog_registerState* state = getState(fsm);

    assert(state != NULL);
    setTransition(fsm, "sm_refresh");
    state->sm_refresh(fsm);
    setTransition(fsm, NULL);
}

void tsip_dialog_registerContext_sm_send(struct tsip_dialog_registerContext* fsm)
{
    const struct tsip_dialog_registerState* state = getState(fsm);

    assert(state != NULL);
    setTransition(fsm, "sm_send");
    state->sm_send(fsm);
    setTransition(fsm, NULL);
}

void tsip_dialog_registerContext_sm_transportError(struct tsip_dialog_registerContext* fsm)
{
    const struct tsip_dialog_registerState* state = getState(fsm);

    assert(state != NULL);
    setTransition(fsm, "sm_transportError");
    state->sm_transportError(fsm);
    setTransition(fsm, NULL);
}

void tsip_dialog_registerContext_sm_unregister(struct tsip_dialog_registerContext* fsm)
{
    const struct tsip_dialog_registerState* state = getState(fsm);

    assert(state != NULL);
    setTransition(fsm, "sm_unregister");
    state->sm_unregister(fsm);
    setTransition(fsm, NULL);
}

/*
 * Local variables:
 *  buffer-read-only: t
 * End:
 */
