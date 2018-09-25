
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Stm.h"
#include "StmRequired.h"
/*! \file Implementation of the state machine 'stm'
*/

/* prototypes of all internal functions */
static sc_boolean stm_check_main_region_Programa_b1_Espera_tr0_tr0(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b1_Presiona_tr0_tr0(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b1_Presiona_tr1_tr1(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b1_Presiona_tr2_tr2(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b1_Presionado_tr0_tr0(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b1_Presionado_tr1_tr1(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b2_Espera_tr0_tr0(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b2_Presiona_tr0_tr0(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b2_Presiona_tr1_tr1(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b2_Presiona_tr2_tr2(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b2_Presionado_tr0_tr0(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b2_Presionado_tr1_tr1(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b3_Espera_tr0_tr0(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b3_Presiona_tr0_tr0(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b3_Presiona_tr1_tr1(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b3_Presiona_tr2_tr2(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b3_Presionado_tr0_tr0(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_b3_Presionado_tr1_tr1(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_Color_Detenido_tr0_tr0(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_Color_Detenido_tr1_tr1(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_Color_Iniciar_tr0_tr0(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_Color_Iniciar_tr1_tr1(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_Color_Iniciar_tr2_tr2(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_Color_Iniciar_lr1_lr1(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_Color_Invertir_tr0_tr0(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_Color_Invertir_tr1_tr1(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_Color_Invertir_tr2_tr2(const Stm* handle);
static sc_boolean stm_check_main_region_Programa_Color_Invertir_lr1_lr1(const Stm* handle);
static void stm_effect_main_region_Programa_b1_Espera_tr0(Stm* handle);
static void stm_effect_main_region_Programa_b1_Presiona_tr0(Stm* handle);
static void stm_effect_main_region_Programa_b1_Presiona_tr1(Stm* handle);
static void stm_effect_main_region_Programa_b1_Presiona_tr2(Stm* handle);
static void stm_effect_main_region_Programa_b1_Presionado_tr0(Stm* handle);
static void stm_effect_main_region_Programa_b1_Presionado_tr1(Stm* handle);
static void stm_effect_main_region_Programa_b2_Espera_tr0(Stm* handle);
static void stm_effect_main_region_Programa_b2_Presiona_tr0(Stm* handle);
static void stm_effect_main_region_Programa_b2_Presiona_tr1(Stm* handle);
static void stm_effect_main_region_Programa_b2_Presiona_tr2(Stm* handle);
static void stm_effect_main_region_Programa_b2_Presionado_tr0(Stm* handle);
static void stm_effect_main_region_Programa_b2_Presionado_tr1(Stm* handle);
static void stm_effect_main_region_Programa_b3_Espera_tr0(Stm* handle);
static void stm_effect_main_region_Programa_b3_Presiona_tr0(Stm* handle);
static void stm_effect_main_region_Programa_b3_Presiona_tr1(Stm* handle);
static void stm_effect_main_region_Programa_b3_Presiona_tr2(Stm* handle);
static void stm_effect_main_region_Programa_b3_Presionado_tr0(Stm* handle);
static void stm_effect_main_region_Programa_b3_Presionado_tr1(Stm* handle);
static void stm_effect_main_region_Programa_Color_Detenido_tr0(Stm* handle);
static void stm_effect_main_region_Programa_Color_Detenido_tr1(Stm* handle);
static void stm_effect_main_region_Programa_Color_Iniciar_tr0(Stm* handle);
static void stm_effect_main_region_Programa_Color_Iniciar_tr1(Stm* handle);
static void stm_effect_main_region_Programa_Color_Iniciar_tr2(Stm* handle);
static void stm_effect_main_region_Programa_Color_Iniciar_lr1_lr1(Stm* handle);
static void stm_effect_main_region_Programa_Color_Invertir_tr0(Stm* handle);
static void stm_effect_main_region_Programa_Color_Invertir_tr1(Stm* handle);
static void stm_effect_main_region_Programa_Color_Invertir_tr2(Stm* handle);
static void stm_effect_main_region_Programa_Color_Invertir_lr1_lr1(Stm* handle);
static void stm_enact_main_region_Programa_Color_Iniciar(Stm* handle);
static void stm_enact_main_region_Programa_Color_Invertir(Stm* handle);
static void stm_enseq_main_region_Programa_default(Stm* handle);
static void stm_enseq_main_region_Programa_b1_Espera_default(Stm* handle);
static void stm_enseq_main_region_Programa_b1_Presiona_default(Stm* handle);
static void stm_enseq_main_region_Programa_b1_Presionado_default(Stm* handle);
static void stm_enseq_main_region_Programa_b2_Espera_default(Stm* handle);
static void stm_enseq_main_region_Programa_b2_Presiona_default(Stm* handle);
static void stm_enseq_main_region_Programa_b2_Presionado_default(Stm* handle);
static void stm_enseq_main_region_Programa_b3_Espera_default(Stm* handle);
static void stm_enseq_main_region_Programa_b3_Presiona_default(Stm* handle);
static void stm_enseq_main_region_Programa_b3_Presionado_default(Stm* handle);
static void stm_enseq_main_region_Programa_Color_Detenido_default(Stm* handle);
static void stm_enseq_main_region_Programa_Color_Iniciar_default(Stm* handle);
static void stm_enseq_main_region_Programa_Color_Invertir_default(Stm* handle);
static void stm_enseq_main_region_default(Stm* handle);
static void stm_enseq_main_region_Programa_b1_default(Stm* handle);
static void stm_enseq_main_region_Programa_b2_default(Stm* handle);
static void stm_enseq_main_region_Programa_b3_default(Stm* handle);
static void stm_enseq_main_region_Programa_Color_default(Stm* handle);
static void stm_exseq_main_region_Programa_b1_Espera(Stm* handle);
static void stm_exseq_main_region_Programa_b1_Presiona(Stm* handle);
static void stm_exseq_main_region_Programa_b1_Presionado(Stm* handle);
static void stm_exseq_main_region_Programa_b2_Espera(Stm* handle);
static void stm_exseq_main_region_Programa_b2_Presiona(Stm* handle);
static void stm_exseq_main_region_Programa_b2_Presionado(Stm* handle);
static void stm_exseq_main_region_Programa_b3_Espera(Stm* handle);
static void stm_exseq_main_region_Programa_b3_Presiona(Stm* handle);
static void stm_exseq_main_region_Programa_b3_Presionado(Stm* handle);
static void stm_exseq_main_region_Programa_Color_Detenido(Stm* handle);
static void stm_exseq_main_region_Programa_Color_Iniciar(Stm* handle);
static void stm_exseq_main_region_Programa_Color_Invertir(Stm* handle);
static void stm_exseq_main_region(Stm* handle);
static void stm_exseq_main_region_Programa_b1(Stm* handle);
static void stm_exseq_main_region_Programa_b2(Stm* handle);
static void stm_exseq_main_region_Programa_b3(Stm* handle);
static void stm_exseq_main_region_Programa_Color(Stm* handle);
static void stm_react_main_region_Programa_b1_Espera(Stm* handle);
static void stm_react_main_region_Programa_b1_Presiona(Stm* handle);
static void stm_react_main_region_Programa_b1_Presionado(Stm* handle);
static void stm_react_main_region_Programa_b2_Espera(Stm* handle);
static void stm_react_main_region_Programa_b2_Presiona(Stm* handle);
static void stm_react_main_region_Programa_b2_Presionado(Stm* handle);
static void stm_react_main_region_Programa_b3_Espera(Stm* handle);
static void stm_react_main_region_Programa_b3_Presiona(Stm* handle);
static void stm_react_main_region_Programa_b3_Presionado(Stm* handle);
static void stm_react_main_region_Programa_Color_Detenido(Stm* handle);
static void stm_react_main_region_Programa_Color_Iniciar(Stm* handle);
static void stm_react_main_region_Programa_Color_Invertir(Stm* handle);
static void stm_react_main_region_Programa_b1__entry_Default(Stm* handle);
static void stm_react_main_region_Programa_b2__entry_Default(Stm* handle);
static void stm_react_main_region_Programa_b3__entry_Default(Stm* handle);
static void stm_react_main_region_Programa_Color__entry_Default(Stm* handle);
static void stm_react_main_region__entry_Default(Stm* handle);
static void stm_clearInEvents(Stm* handle);
static void stm_clearOutEvents(Stm* handle);

const sc_integer STM_STMINTERNAL_DEBTIC = 10;
const sc_integer STM_STMINTERNAL_COLOR_MAX = 7;
const sc_integer STM_STMINTERNAL_COLOR_MIN = 0;

void stm_init(Stm* handle)
{
	sc_integer i;

	for (i = 0; i < STM_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Stm_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	stm_clearInEvents(handle);
	stm_clearOutEvents(handle);

	/* Default init sequence for statechart stm */
	handle->iface.bBoton1 = bool_false;
	handle->iface.bBoton2 = bool_false;
	handle->iface.bBoton3 = bool_false;
	handle->internal.tic1 = 0;
	handle->internal.tic2 = 0;
	handle->internal.tic3 = 0;
	handle->internal.color_num = 0;

}

void stm_enter(Stm* handle)
{
	/* Default enter sequence for statechart stm */
	stm_enseq_main_region_default(handle);
}

void stm_exit(Stm* handle)
{
	/* Default exit sequence for statechart stm */
	stm_exseq_main_region(handle);
}

sc_boolean stm_isActive(const Stm* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Stm_last_state || handle->stateConfVector[1] != Stm_last_state || handle->stateConfVector[2] != Stm_last_state || handle->stateConfVector[3] != Stm_last_state)
	{
		result =  bool_true;
	}
	else
	{
		result = bool_false;
	}
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean stm_isFinal(const Stm* handle)
{
   return bool_false;
}

static void stm_clearInEvents(Stm* handle)
{
	handle->iface.eTic_raised = bool_false;
	handle->iface.eTime_raised = bool_false;
	handle->internal.eBoton1_raised = bool_false;
	handle->internal.eBoton2_raised = bool_false;
	handle->internal.eBoton3_raised = bool_false;
}

static void stm_clearOutEvents(Stm* handle)
{
}

void stm_runCycle(Stm* handle)
{
	
	stm_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < STM_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Stm_main_region_Programa_b1_Espera :
		{
			stm_react_main_region_Programa_b1_Espera(handle);
			break;
		}
		case Stm_main_region_Programa_b1_Presiona :
		{
			stm_react_main_region_Programa_b1_Presiona(handle);
			break;
		}
		case Stm_main_region_Programa_b1_Presionado :
		{
			stm_react_main_region_Programa_b1_Presionado(handle);
			break;
		}
		case Stm_main_region_Programa_b2_Espera :
		{
			stm_react_main_region_Programa_b2_Espera(handle);
			break;
		}
		case Stm_main_region_Programa_b2_Presiona :
		{
			stm_react_main_region_Programa_b2_Presiona(handle);
			break;
		}
		case Stm_main_region_Programa_b2_Presionado :
		{
			stm_react_main_region_Programa_b2_Presionado(handle);
			break;
		}
		case Stm_main_region_Programa_b3_Espera :
		{
			stm_react_main_region_Programa_b3_Espera(handle);
			break;
		}
		case Stm_main_region_Programa_b3_Presiona :
		{
			stm_react_main_region_Programa_b3_Presiona(handle);
			break;
		}
		case Stm_main_region_Programa_b3_Presionado :
		{
			stm_react_main_region_Programa_b3_Presionado(handle);
			break;
		}
		case Stm_main_region_Programa_Color_Detenido :
		{
			stm_react_main_region_Programa_Color_Detenido(handle);
			break;
		}
		case Stm_main_region_Programa_Color_Iniciar :
		{
			stm_react_main_region_Programa_Color_Iniciar(handle);
			break;
		}
		case Stm_main_region_Programa_Color_Invertir :
		{
			stm_react_main_region_Programa_Color_Invertir(handle);
			break;
		}
		default:
			break;
		}
	}
	
	stm_clearInEvents(handle);
}


sc_boolean stm_isStateActive(const Stm* handle, StmStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Stm_main_region_Programa :
			result = (sc_boolean) (handle->stateConfVector[0] >= Stm_main_region_Programa
				&& handle->stateConfVector[0] <= Stm_main_region_Programa_Color_Invertir);
			break;
		case Stm_main_region_Programa_b1_Espera :
			result = (sc_boolean) (handle->stateConfVector[0] == Stm_main_region_Programa_b1_Espera
			);
			break;
		case Stm_main_region_Programa_b1_Presiona :
			result = (sc_boolean) (handle->stateConfVector[0] == Stm_main_region_Programa_b1_Presiona
			);
			break;
		case Stm_main_region_Programa_b1_Presionado :
			result = (sc_boolean) (handle->stateConfVector[0] == Stm_main_region_Programa_b1_Presionado
			);
			break;
		case Stm_main_region_Programa_b2_Espera :
			result = (sc_boolean) (handle->stateConfVector[1] == Stm_main_region_Programa_b2_Espera
			);
			break;
		case Stm_main_region_Programa_b2_Presiona :
			result = (sc_boolean) (handle->stateConfVector[1] == Stm_main_region_Programa_b2_Presiona
			);
			break;
		case Stm_main_region_Programa_b2_Presionado :
			result = (sc_boolean) (handle->stateConfVector[1] == Stm_main_region_Programa_b2_Presionado
			);
			break;
		case Stm_main_region_Programa_b3_Espera :
			result = (sc_boolean) (handle->stateConfVector[2] == Stm_main_region_Programa_b3_Espera
			);
			break;
		case Stm_main_region_Programa_b3_Presiona :
			result = (sc_boolean) (handle->stateConfVector[2] == Stm_main_region_Programa_b3_Presiona
			);
			break;
		case Stm_main_region_Programa_b3_Presionado :
			result = (sc_boolean) (handle->stateConfVector[2] == Stm_main_region_Programa_b3_Presionado
			);
			break;
		case Stm_main_region_Programa_Color_Detenido :
			result = (sc_boolean) (handle->stateConfVector[3] == Stm_main_region_Programa_Color_Detenido
			);
			break;
		case Stm_main_region_Programa_Color_Iniciar :
			result = (sc_boolean) (handle->stateConfVector[3] == Stm_main_region_Programa_Color_Iniciar
			);
			break;
		case Stm_main_region_Programa_Color_Invertir :
			result = (sc_boolean) (handle->stateConfVector[3] == Stm_main_region_Programa_Color_Invertir
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void stmIface_raise_eTic(Stm* handle)
{
	handle->iface.eTic_raised = bool_true;
}
void stmIface_raise_eTime(Stm* handle)
{
	handle->iface.eTime_raised = bool_true;
}


sc_boolean stmIface_get_bBoton1(const Stm* handle)
{
	return handle->iface.bBoton1;
}
void stmIface_set_bBoton1(Stm* handle, sc_boolean value)
{
	handle->iface.bBoton1 = value;
}
sc_boolean stmIface_get_bBoton2(const Stm* handle)
{
	return handle->iface.bBoton2;
}
void stmIface_set_bBoton2(Stm* handle, sc_boolean value)
{
	handle->iface.bBoton2 = value;
}
sc_boolean stmIface_get_bBoton3(const Stm* handle)
{
	return handle->iface.bBoton3;
}
void stmIface_set_bBoton3(Stm* handle, sc_boolean value)
{
	handle->iface.bBoton3 = value;
}

/* implementations of all internal functions */

static sc_boolean stm_check_main_region_Programa_b1_Espera_tr0_tr0(const Stm* handle)
{
	return (handle->iface.bBoton1 == bool_true) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b1_Presiona_tr0_tr0(const Stm* handle)
{
	return (handle->iface.bBoton1 == bool_true && handle->internal.tic1 == 0) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b1_Presiona_tr1_tr1(const Stm* handle)
{
	return (handle->iface.bBoton1 == bool_false && handle->internal.tic1 == 0) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b1_Presiona_tr2_tr2(const Stm* handle)
{
	return ((handle->iface.eTic_raised) && (handle->internal.tic1 > 0)) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b1_Presionado_tr0_tr0(const Stm* handle)
{
	return (handle->iface.bBoton1 == bool_true) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b1_Presionado_tr1_tr1(const Stm* handle)
{
	return (handle->iface.bBoton1 == bool_false) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b2_Espera_tr0_tr0(const Stm* handle)
{
	return (handle->iface.bBoton2 == bool_true) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b2_Presiona_tr0_tr0(const Stm* handle)
{
	return (handle->iface.bBoton2 == bool_true && handle->internal.tic2 == 0) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b2_Presiona_tr1_tr1(const Stm* handle)
{
	return ((handle->iface.eTic_raised) && (handle->internal.tic2 > 0)) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b2_Presiona_tr2_tr2(const Stm* handle)
{
	return (handle->iface.bBoton2 == bool_false && handle->internal.tic2 == 0) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b2_Presionado_tr0_tr0(const Stm* handle)
{
	return (handle->iface.bBoton2 == bool_true) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b2_Presionado_tr1_tr1(const Stm* handle)
{
	return (handle->iface.bBoton2 == bool_false) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b3_Espera_tr0_tr0(const Stm* handle)
{
	return (handle->iface.bBoton3 == bool_true) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b3_Presiona_tr0_tr0(const Stm* handle)
{
	return (handle->iface.bBoton3 == bool_true && handle->internal.tic3 == 0) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b3_Presiona_tr1_tr1(const Stm* handle)
{
	return ((handle->iface.eTic_raised) && (handle->internal.tic3 > 0)) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b3_Presiona_tr2_tr2(const Stm* handle)
{
	return (handle->iface.bBoton3 == bool_false && handle->internal.tic3 == 0) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b3_Presionado_tr0_tr0(const Stm* handle)
{
	return (handle->iface.bBoton3 == bool_true) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_b3_Presionado_tr1_tr1(const Stm* handle)
{
	return (handle->iface.bBoton3 == bool_false) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_Color_Detenido_tr0_tr0(const Stm* handle)
{
	return (handle->internal.eBoton1_raised == bool_true) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_Color_Detenido_tr1_tr1(const Stm* handle)
{
	return handle->internal.eBoton2_raised;
}

static sc_boolean stm_check_main_region_Programa_Color_Iniciar_tr0_tr0(const Stm* handle)
{
	return (handle->internal.eBoton3_raised == bool_true) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_Color_Iniciar_tr1_tr1(const Stm* handle)
{
	return (handle->internal.eBoton2_raised == bool_true) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_Color_Iniciar_tr2_tr2(const Stm* handle)
{
	return handle->iface.eTime_raised;
}

static sc_boolean stm_check_main_region_Programa_Color_Iniciar_lr1_lr1(const Stm* handle)
{
	return (handle->internal.color_num == STM_STMINTERNAL_COLOR_MAX) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_Color_Invertir_tr0_tr0(const Stm* handle)
{
	return (handle->internal.eBoton1_raised == bool_true) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_Color_Invertir_tr1_tr1(const Stm* handle)
{
	return (handle->internal.eBoton3_raised == bool_true) ? bool_true : bool_false;
}

static sc_boolean stm_check_main_region_Programa_Color_Invertir_tr2_tr2(const Stm* handle)
{
	return handle->iface.eTime_raised;
}

static sc_boolean stm_check_main_region_Programa_Color_Invertir_lr1_lr1(const Stm* handle)
{
	return (handle->internal.color_num == STM_STMINTERNAL_COLOR_MIN) ? bool_true : bool_false;
}

static void stm_effect_main_region_Programa_b1_Espera_tr0(Stm* handle)
{
	stm_exseq_main_region_Programa_b1_Espera(handle);
	handle->internal.tic1 = STM_STMINTERNAL_DEBTIC;
	stm_enseq_main_region_Programa_b1_Presiona_default(handle);
}

static void stm_effect_main_region_Programa_b1_Presiona_tr0(Stm* handle)
{
	stm_exseq_main_region_Programa_b1_Presiona(handle);
	handle->internal.eBoton1_raised = bool_true;
	stm_enseq_main_region_Programa_b1_Presionado_default(handle);
}

static void stm_effect_main_region_Programa_b1_Presiona_tr1(Stm* handle)
{
	stm_exseq_main_region_Programa_b1_Presiona(handle);
	stm_enseq_main_region_Programa_b1_Espera_default(handle);
}

static void stm_effect_main_region_Programa_b1_Presiona_tr2(Stm* handle)
{
	stm_exseq_main_region_Programa_b1_Presiona(handle);
	handle->internal.tic1 -= 1;
	stm_enseq_main_region_Programa_b1_Presiona_default(handle);
}

static void stm_effect_main_region_Programa_b1_Presionado_tr0(Stm* handle)
{
	stm_exseq_main_region_Programa_b1_Presionado(handle);
	stm_enseq_main_region_Programa_b1_Presionado_default(handle);
}

static void stm_effect_main_region_Programa_b1_Presionado_tr1(Stm* handle)
{
	stm_exseq_main_region_Programa_b1_Presionado(handle);
	stm_enseq_main_region_Programa_b1_Espera_default(handle);
}

static void stm_effect_main_region_Programa_b2_Espera_tr0(Stm* handle)
{
	stm_exseq_main_region_Programa_b2_Espera(handle);
	handle->internal.tic2 = STM_STMINTERNAL_DEBTIC;
	stm_enseq_main_region_Programa_b2_Presiona_default(handle);
}

static void stm_effect_main_region_Programa_b2_Presiona_tr0(Stm* handle)
{
	stm_exseq_main_region_Programa_b2_Presiona(handle);
	handle->internal.eBoton2_raised = bool_true;
	stm_enseq_main_region_Programa_b2_Presionado_default(handle);
}

static void stm_effect_main_region_Programa_b2_Presiona_tr1(Stm* handle)
{
	stm_exseq_main_region_Programa_b2_Presiona(handle);
	handle->internal.tic2 -= 1;
	stm_enseq_main_region_Programa_b2_Presiona_default(handle);
}

static void stm_effect_main_region_Programa_b2_Presiona_tr2(Stm* handle)
{
	stm_exseq_main_region_Programa_b2_Presiona(handle);
	stm_enseq_main_region_Programa_b2_Espera_default(handle);
}

static void stm_effect_main_region_Programa_b2_Presionado_tr0(Stm* handle)
{
	stm_exseq_main_region_Programa_b2_Presionado(handle);
	stm_enseq_main_region_Programa_b2_Presionado_default(handle);
}

static void stm_effect_main_region_Programa_b2_Presionado_tr1(Stm* handle)
{
	stm_exseq_main_region_Programa_b2_Presionado(handle);
	stm_enseq_main_region_Programa_b2_Espera_default(handle);
}

static void stm_effect_main_region_Programa_b3_Espera_tr0(Stm* handle)
{
	stm_exseq_main_region_Programa_b3_Espera(handle);
	handle->internal.tic3 = STM_STMINTERNAL_DEBTIC;
	stm_enseq_main_region_Programa_b3_Presiona_default(handle);
}

static void stm_effect_main_region_Programa_b3_Presiona_tr0(Stm* handle)
{
	stm_exseq_main_region_Programa_b3_Presiona(handle);
	handle->internal.eBoton3_raised = bool_true;
	stm_enseq_main_region_Programa_b3_Presionado_default(handle);
}

static void stm_effect_main_region_Programa_b3_Presiona_tr1(Stm* handle)
{
	stm_exseq_main_region_Programa_b3_Presiona(handle);
	handle->internal.tic3 -= 1;
	stm_enseq_main_region_Programa_b3_Presiona_default(handle);
}

static void stm_effect_main_region_Programa_b3_Presiona_tr2(Stm* handle)
{
	stm_exseq_main_region_Programa_b3_Presiona(handle);
	stm_enseq_main_region_Programa_b3_Espera_default(handle);
}

static void stm_effect_main_region_Programa_b3_Presionado_tr0(Stm* handle)
{
	stm_exseq_main_region_Programa_b3_Presionado(handle);
	stm_enseq_main_region_Programa_b3_Presionado_default(handle);
}

static void stm_effect_main_region_Programa_b3_Presionado_tr1(Stm* handle)
{
	stm_exseq_main_region_Programa_b3_Presionado(handle);
	stm_enseq_main_region_Programa_b3_Espera_default(handle);
}

static void stm_effect_main_region_Programa_Color_Detenido_tr0(Stm* handle)
{
	stm_exseq_main_region_Programa_Color_Detenido(handle);
	handle->internal.color_num = STM_STMINTERNAL_COLOR_MIN;
	stm_enseq_main_region_Programa_Color_Iniciar_default(handle);
}

static void stm_effect_main_region_Programa_Color_Detenido_tr1(Stm* handle)
{
	stm_exseq_main_region_Programa_Color_Detenido(handle);
	handle->internal.color_num = STM_STMINTERNAL_COLOR_MAX;
	stm_enseq_main_region_Programa_Color_Invertir_default(handle);
}

static void stm_effect_main_region_Programa_Color_Iniciar_tr0(Stm* handle)
{
	stm_exseq_main_region_Programa_Color_Iniciar(handle);
	stm_enseq_main_region_Programa_Color_Detenido_default(handle);
}

static void stm_effect_main_region_Programa_Color_Iniciar_tr1(Stm* handle)
{
	stm_exseq_main_region_Programa_Color_Iniciar(handle);
	handle->internal.color_num -= 1;
	stm_enseq_main_region_Programa_Color_Invertir_default(handle);
}

static void stm_effect_main_region_Programa_Color_Iniciar_tr2(Stm* handle)
{
	stm_exseq_main_region_Programa_Color_Iniciar(handle);
	handle->internal.color_num += 1;
	stm_enseq_main_region_Programa_Color_Iniciar_default(handle);
}

static void stm_effect_main_region_Programa_Color_Iniciar_lr1_lr1(Stm* handle)
{
	handle->internal.color_num = 0;
}

static void stm_effect_main_region_Programa_Color_Invertir_tr0(Stm* handle)
{
	stm_exseq_main_region_Programa_Color_Invertir(handle);
	handle->internal.color_num += 1;
	stm_enseq_main_region_Programa_Color_Iniciar_default(handle);
}

static void stm_effect_main_region_Programa_Color_Invertir_tr1(Stm* handle)
{
	stm_exseq_main_region_Programa_Color_Invertir(handle);
	stm_enseq_main_region_Programa_Color_Detenido_default(handle);
}

static void stm_effect_main_region_Programa_Color_Invertir_tr2(Stm* handle)
{
	stm_exseq_main_region_Programa_Color_Invertir(handle);
	handle->internal.color_num -= 1;
	stm_enseq_main_region_Programa_Color_Invertir_default(handle);
}

static void stm_effect_main_region_Programa_Color_Invertir_lr1_lr1(Stm* handle)
{
	handle->internal.color_num = STM_STMINTERNAL_COLOR_MAX;
}

/* Entry action for state 'Iniciar'. */
static void stm_enact_main_region_Programa_Color_Iniciar(Stm* handle)
{
	/* Entry action for state 'Iniciar'. */
	stmIface_setColor(handle, handle->internal.color_num);
}

/* Entry action for state 'Invertir'. */
static void stm_enact_main_region_Programa_Color_Invertir(Stm* handle)
{
	/* Entry action for state 'Invertir'. */
	stmIface_setColor(handle, handle->internal.color_num);
}

/* 'default' enter sequence for state Programa */
static void stm_enseq_main_region_Programa_default(Stm* handle)
{
	/* 'default' enter sequence for state Programa */
	stm_enseq_main_region_Programa_b1_default(handle);
	stm_enseq_main_region_Programa_b2_default(handle);
	stm_enseq_main_region_Programa_b3_default(handle);
	stm_enseq_main_region_Programa_Color_default(handle);
}

/* 'default' enter sequence for state Espera */
static void stm_enseq_main_region_Programa_b1_Espera_default(Stm* handle)
{
	/* 'default' enter sequence for state Espera */
	handle->stateConfVector[0] = Stm_main_region_Programa_b1_Espera;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Presiona */
static void stm_enseq_main_region_Programa_b1_Presiona_default(Stm* handle)
{
	/* 'default' enter sequence for state Presiona */
	handle->stateConfVector[0] = Stm_main_region_Programa_b1_Presiona;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Presionado */
static void stm_enseq_main_region_Programa_b1_Presionado_default(Stm* handle)
{
	/* 'default' enter sequence for state Presionado */
	handle->stateConfVector[0] = Stm_main_region_Programa_b1_Presionado;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Espera */
static void stm_enseq_main_region_Programa_b2_Espera_default(Stm* handle)
{
	/* 'default' enter sequence for state Espera */
	handle->stateConfVector[1] = Stm_main_region_Programa_b2_Espera;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state Presiona */
static void stm_enseq_main_region_Programa_b2_Presiona_default(Stm* handle)
{
	/* 'default' enter sequence for state Presiona */
	handle->stateConfVector[1] = Stm_main_region_Programa_b2_Presiona;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state Presionado */
static void stm_enseq_main_region_Programa_b2_Presionado_default(Stm* handle)
{
	/* 'default' enter sequence for state Presionado */
	handle->stateConfVector[1] = Stm_main_region_Programa_b2_Presionado;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state Espera */
static void stm_enseq_main_region_Programa_b3_Espera_default(Stm* handle)
{
	/* 'default' enter sequence for state Espera */
	handle->stateConfVector[2] = Stm_main_region_Programa_b3_Espera;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Presiona */
static void stm_enseq_main_region_Programa_b3_Presiona_default(Stm* handle)
{
	/* 'default' enter sequence for state Presiona */
	handle->stateConfVector[2] = Stm_main_region_Programa_b3_Presiona;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Presionado */
static void stm_enseq_main_region_Programa_b3_Presionado_default(Stm* handle)
{
	/* 'default' enter sequence for state Presionado */
	handle->stateConfVector[2] = Stm_main_region_Programa_b3_Presionado;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Detenido */
static void stm_enseq_main_region_Programa_Color_Detenido_default(Stm* handle)
{
	/* 'default' enter sequence for state Detenido */
	handle->stateConfVector[3] = Stm_main_region_Programa_Color_Detenido;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state Iniciar */
static void stm_enseq_main_region_Programa_Color_Iniciar_default(Stm* handle)
{
	/* 'default' enter sequence for state Iniciar */
	stm_enact_main_region_Programa_Color_Iniciar(handle);
	handle->stateConfVector[3] = Stm_main_region_Programa_Color_Iniciar;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state Invertir */
static void stm_enseq_main_region_Programa_Color_Invertir_default(Stm* handle)
{
	/* 'default' enter sequence for state Invertir */
	stm_enact_main_region_Programa_Color_Invertir(handle);
	handle->stateConfVector[3] = Stm_main_region_Programa_Color_Invertir;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for region main region */
static void stm_enseq_main_region_default(Stm* handle)
{
	/* 'default' enter sequence for region main region */
	stm_react_main_region__entry_Default(handle);
}

/* 'default' enter sequence for region b1 */
static void stm_enseq_main_region_Programa_b1_default(Stm* handle)
{
	/* 'default' enter sequence for region b1 */
	stm_react_main_region_Programa_b1__entry_Default(handle);
}

/* 'default' enter sequence for region b2 */
static void stm_enseq_main_region_Programa_b2_default(Stm* handle)
{
	/* 'default' enter sequence for region b2 */
	stm_react_main_region_Programa_b2__entry_Default(handle);
}

/* 'default' enter sequence for region b3 */
static void stm_enseq_main_region_Programa_b3_default(Stm* handle)
{
	/* 'default' enter sequence for region b3 */
	stm_react_main_region_Programa_b3__entry_Default(handle);
}

/* 'default' enter sequence for region Color */
static void stm_enseq_main_region_Programa_Color_default(Stm* handle)
{
	/* 'default' enter sequence for region Color */
	stm_react_main_region_Programa_Color__entry_Default(handle);
}

/* Default exit sequence for state Espera */
static void stm_exseq_main_region_Programa_b1_Espera(Stm* handle)
{
	/* Default exit sequence for state Espera */
	handle->stateConfVector[0] = Stm_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Presiona */
static void stm_exseq_main_region_Programa_b1_Presiona(Stm* handle)
{
	/* Default exit sequence for state Presiona */
	handle->stateConfVector[0] = Stm_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Presionado */
static void stm_exseq_main_region_Programa_b1_Presionado(Stm* handle)
{
	/* Default exit sequence for state Presionado */
	handle->stateConfVector[0] = Stm_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Espera */
static void stm_exseq_main_region_Programa_b2_Espera(Stm* handle)
{
	/* Default exit sequence for state Espera */
	handle->stateConfVector[1] = Stm_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state Presiona */
static void stm_exseq_main_region_Programa_b2_Presiona(Stm* handle)
{
	/* Default exit sequence for state Presiona */
	handle->stateConfVector[1] = Stm_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state Presionado */
static void stm_exseq_main_region_Programa_b2_Presionado(Stm* handle)
{
	/* Default exit sequence for state Presionado */
	handle->stateConfVector[1] = Stm_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state Espera */
static void stm_exseq_main_region_Programa_b3_Espera(Stm* handle)
{
	/* Default exit sequence for state Espera */
	handle->stateConfVector[2] = Stm_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state Presiona */
static void stm_exseq_main_region_Programa_b3_Presiona(Stm* handle)
{
	/* Default exit sequence for state Presiona */
	handle->stateConfVector[2] = Stm_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state Presionado */
static void stm_exseq_main_region_Programa_b3_Presionado(Stm* handle)
{
	/* Default exit sequence for state Presionado */
	handle->stateConfVector[2] = Stm_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state Detenido */
static void stm_exseq_main_region_Programa_Color_Detenido(Stm* handle)
{
	/* Default exit sequence for state Detenido */
	handle->stateConfVector[3] = Stm_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state Iniciar */
static void stm_exseq_main_region_Programa_Color_Iniciar(Stm* handle)
{
	/* Default exit sequence for state Iniciar */
	handle->stateConfVector[3] = Stm_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state Invertir */
static void stm_exseq_main_region_Programa_Color_Invertir(Stm* handle)
{
	/* Default exit sequence for state Invertir */
	handle->stateConfVector[3] = Stm_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for region main region */
static void stm_exseq_main_region(Stm* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of stm.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Stm_main_region_Programa_b1_Espera :
		{
			stm_exseq_main_region_Programa_b1_Espera(handle);
			break;
		}
		case Stm_main_region_Programa_b1_Presiona :
		{
			stm_exseq_main_region_Programa_b1_Presiona(handle);
			break;
		}
		case Stm_main_region_Programa_b1_Presionado :
		{
			stm_exseq_main_region_Programa_b1_Presionado(handle);
			break;
		}
		default: break;
	}
	/* Handle exit of all possible states (of stm.main_region) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Stm_main_region_Programa_b2_Espera :
		{
			stm_exseq_main_region_Programa_b2_Espera(handle);
			break;
		}
		case Stm_main_region_Programa_b2_Presiona :
		{
			stm_exseq_main_region_Programa_b2_Presiona(handle);
			break;
		}
		case Stm_main_region_Programa_b2_Presionado :
		{
			stm_exseq_main_region_Programa_b2_Presionado(handle);
			break;
		}
		default: break;
	}
	/* Handle exit of all possible states (of stm.main_region) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Stm_main_region_Programa_b3_Espera :
		{
			stm_exseq_main_region_Programa_b3_Espera(handle);
			break;
		}
		case Stm_main_region_Programa_b3_Presiona :
		{
			stm_exseq_main_region_Programa_b3_Presiona(handle);
			break;
		}
		case Stm_main_region_Programa_b3_Presionado :
		{
			stm_exseq_main_region_Programa_b3_Presionado(handle);
			break;
		}
		default: break;
	}
	/* Handle exit of all possible states (of stm.main_region) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Stm_main_region_Programa_Color_Detenido :
		{
			stm_exseq_main_region_Programa_Color_Detenido(handle);
			break;
		}
		case Stm_main_region_Programa_Color_Iniciar :
		{
			stm_exseq_main_region_Programa_Color_Iniciar(handle);
			break;
		}
		case Stm_main_region_Programa_Color_Invertir :
		{
			stm_exseq_main_region_Programa_Color_Invertir(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region b1 */
static void stm_exseq_main_region_Programa_b1(Stm* handle)
{
	/* Default exit sequence for region b1 */
	/* Handle exit of all possible states (of stm.main_region.Programa.b1) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Stm_main_region_Programa_b1_Espera :
		{
			stm_exseq_main_region_Programa_b1_Espera(handle);
			break;
		}
		case Stm_main_region_Programa_b1_Presiona :
		{
			stm_exseq_main_region_Programa_b1_Presiona(handle);
			break;
		}
		case Stm_main_region_Programa_b1_Presionado :
		{
			stm_exseq_main_region_Programa_b1_Presionado(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region b2 */
static void stm_exseq_main_region_Programa_b2(Stm* handle)
{
	/* Default exit sequence for region b2 */
	/* Handle exit of all possible states (of stm.main_region.Programa.b2) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Stm_main_region_Programa_b2_Espera :
		{
			stm_exseq_main_region_Programa_b2_Espera(handle);
			break;
		}
		case Stm_main_region_Programa_b2_Presiona :
		{
			stm_exseq_main_region_Programa_b2_Presiona(handle);
			break;
		}
		case Stm_main_region_Programa_b2_Presionado :
		{
			stm_exseq_main_region_Programa_b2_Presionado(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region b3 */
static void stm_exseq_main_region_Programa_b3(Stm* handle)
{
	/* Default exit sequence for region b3 */
	/* Handle exit of all possible states (of stm.main_region.Programa.b3) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Stm_main_region_Programa_b3_Espera :
		{
			stm_exseq_main_region_Programa_b3_Espera(handle);
			break;
		}
		case Stm_main_region_Programa_b3_Presiona :
		{
			stm_exseq_main_region_Programa_b3_Presiona(handle);
			break;
		}
		case Stm_main_region_Programa_b3_Presionado :
		{
			stm_exseq_main_region_Programa_b3_Presionado(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Color */
static void stm_exseq_main_region_Programa_Color(Stm* handle)
{
	/* Default exit sequence for region Color */
	/* Handle exit of all possible states (of stm.main_region.Programa.Color) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Stm_main_region_Programa_Color_Detenido :
		{
			stm_exseq_main_region_Programa_Color_Detenido(handle);
			break;
		}
		case Stm_main_region_Programa_Color_Iniciar :
		{
			stm_exseq_main_region_Programa_Color_Iniciar(handle);
			break;
		}
		case Stm_main_region_Programa_Color_Invertir :
		{
			stm_exseq_main_region_Programa_Color_Invertir(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state Espera. */
static void stm_react_main_region_Programa_b1_Espera(Stm* handle)
{
	/* The reactions of state Espera. */
	if (stm_check_main_region_Programa_b1_Espera_tr0_tr0(handle) == bool_true)
	{ 
		stm_effect_main_region_Programa_b1_Espera_tr0(handle);
	} 
}

/* The reactions of state Presiona. */
static void stm_react_main_region_Programa_b1_Presiona(Stm* handle)
{
	/* The reactions of state Presiona. */
	if (stm_check_main_region_Programa_b1_Presiona_tr0_tr0(handle) == bool_true)
	{ 
		stm_effect_main_region_Programa_b1_Presiona_tr0(handle);
	}  else
	{
		if (stm_check_main_region_Programa_b1_Presiona_tr1_tr1(handle) == bool_true)
		{ 
			stm_effect_main_region_Programa_b1_Presiona_tr1(handle);
		}  else
		{
			if (stm_check_main_region_Programa_b1_Presiona_tr2_tr2(handle) == bool_true)
			{ 
				stm_effect_main_region_Programa_b1_Presiona_tr2(handle);
			} 
		}
	}
}

/* The reactions of state Presionado. */
static void stm_react_main_region_Programa_b1_Presionado(Stm* handle)
{
	/* The reactions of state Presionado. */
	if (stm_check_main_region_Programa_b1_Presionado_tr0_tr0(handle) == bool_true)
	{ 
		stm_effect_main_region_Programa_b1_Presionado_tr0(handle);
	}  else
	{
		if (stm_check_main_region_Programa_b1_Presionado_tr1_tr1(handle) == bool_true)
		{ 
			stm_effect_main_region_Programa_b1_Presionado_tr1(handle);
		} 
	}
}

/* The reactions of state Espera. */
static void stm_react_main_region_Programa_b2_Espera(Stm* handle)
{
	/* The reactions of state Espera. */
	if (stm_check_main_region_Programa_b2_Espera_tr0_tr0(handle) == bool_true)
	{ 
		stm_effect_main_region_Programa_b2_Espera_tr0(handle);
	} 
}

/* The reactions of state Presiona. */
static void stm_react_main_region_Programa_b2_Presiona(Stm* handle)
{
	/* The reactions of state Presiona. */
	if (stm_check_main_region_Programa_b2_Presiona_tr0_tr0(handle) == bool_true)
	{ 
		stm_effect_main_region_Programa_b2_Presiona_tr0(handle);
	}  else
	{
		if (stm_check_main_region_Programa_b2_Presiona_tr1_tr1(handle) == bool_true)
		{ 
			stm_effect_main_region_Programa_b2_Presiona_tr1(handle);
		}  else
		{
			if (stm_check_main_region_Programa_b2_Presiona_tr2_tr2(handle) == bool_true)
			{ 
				stm_effect_main_region_Programa_b2_Presiona_tr2(handle);
			} 
		}
	}
}

/* The reactions of state Presionado. */
static void stm_react_main_region_Programa_b2_Presionado(Stm* handle)
{
	/* The reactions of state Presionado. */
	if (stm_check_main_region_Programa_b2_Presionado_tr0_tr0(handle) == bool_true)
	{ 
		stm_effect_main_region_Programa_b2_Presionado_tr0(handle);
	}  else
	{
		if (stm_check_main_region_Programa_b2_Presionado_tr1_tr1(handle) == bool_true)
		{ 
			stm_effect_main_region_Programa_b2_Presionado_tr1(handle);
		} 
	}
}

/* The reactions of state Espera. */
static void stm_react_main_region_Programa_b3_Espera(Stm* handle)
{
	/* The reactions of state Espera. */
	if (stm_check_main_region_Programa_b3_Espera_tr0_tr0(handle) == bool_true)
	{ 
		stm_effect_main_region_Programa_b3_Espera_tr0(handle);
	} 
}

/* The reactions of state Presiona. */
static void stm_react_main_region_Programa_b3_Presiona(Stm* handle)
{
	/* The reactions of state Presiona. */
	if (stm_check_main_region_Programa_b3_Presiona_tr0_tr0(handle) == bool_true)
	{ 
		stm_effect_main_region_Programa_b3_Presiona_tr0(handle);
	}  else
	{
		if (stm_check_main_region_Programa_b3_Presiona_tr1_tr1(handle) == bool_true)
		{ 
			stm_effect_main_region_Programa_b3_Presiona_tr1(handle);
		}  else
		{
			if (stm_check_main_region_Programa_b3_Presiona_tr2_tr2(handle) == bool_true)
			{ 
				stm_effect_main_region_Programa_b3_Presiona_tr2(handle);
			} 
		}
	}
}

/* The reactions of state Presionado. */
static void stm_react_main_region_Programa_b3_Presionado(Stm* handle)
{
	/* The reactions of state Presionado. */
	if (stm_check_main_region_Programa_b3_Presionado_tr0_tr0(handle) == bool_true)
	{ 
		stm_effect_main_region_Programa_b3_Presionado_tr0(handle);
	}  else
	{
		if (stm_check_main_region_Programa_b3_Presionado_tr1_tr1(handle) == bool_true)
		{ 
			stm_effect_main_region_Programa_b3_Presionado_tr1(handle);
		} 
	}
}

/* The reactions of state Detenido. */
static void stm_react_main_region_Programa_Color_Detenido(Stm* handle)
{
	/* The reactions of state Detenido. */
	if (stm_check_main_region_Programa_Color_Detenido_tr0_tr0(handle) == bool_true)
	{ 
		stm_effect_main_region_Programa_Color_Detenido_tr0(handle);
	}  else
	{
		if (stm_check_main_region_Programa_Color_Detenido_tr1_tr1(handle) == bool_true)
		{ 
			stm_effect_main_region_Programa_Color_Detenido_tr1(handle);
		} 
	}
}

/* The reactions of state Iniciar. */
static void stm_react_main_region_Programa_Color_Iniciar(Stm* handle)
{
	/* The reactions of state Iniciar. */
	if (stm_check_main_region_Programa_Color_Iniciar_tr0_tr0(handle) == bool_true)
	{ 
		stm_effect_main_region_Programa_Color_Iniciar_tr0(handle);
	}  else
	{
		if (stm_check_main_region_Programa_Color_Iniciar_tr1_tr1(handle) == bool_true)
		{ 
			stm_effect_main_region_Programa_Color_Iniciar_tr1(handle);
		}  else
		{
			if (stm_check_main_region_Programa_Color_Iniciar_tr2_tr2(handle) == bool_true)
			{ 
				stm_effect_main_region_Programa_Color_Iniciar_tr2(handle);
			}  else
			{
				if (stm_check_main_region_Programa_Color_Iniciar_lr1_lr1(handle) == bool_true)
				{ 
					stm_effect_main_region_Programa_Color_Iniciar_lr1_lr1(handle);
				} 
			}
		}
	}
}

/* The reactions of state Invertir. */
static void stm_react_main_region_Programa_Color_Invertir(Stm* handle)
{
	/* The reactions of state Invertir. */
	if (stm_check_main_region_Programa_Color_Invertir_tr0_tr0(handle) == bool_true)
	{ 
		stm_effect_main_region_Programa_Color_Invertir_tr0(handle);
	}  else
	{
		if (stm_check_main_region_Programa_Color_Invertir_tr1_tr1(handle) == bool_true)
		{ 
			stm_effect_main_region_Programa_Color_Invertir_tr1(handle);
		}  else
		{
			if (stm_check_main_region_Programa_Color_Invertir_tr2_tr2(handle) == bool_true)
			{ 
				stm_effect_main_region_Programa_Color_Invertir_tr2(handle);
			}  else
			{
				if (stm_check_main_region_Programa_Color_Invertir_lr1_lr1(handle) == bool_true)
				{ 
					stm_effect_main_region_Programa_Color_Invertir_lr1_lr1(handle);
				} 
			}
		}
	}
}

/* Default react sequence for initial entry  */
static void stm_react_main_region_Programa_b1__entry_Default(Stm* handle)
{
	/* Default react sequence for initial entry  */
	stm_enseq_main_region_Programa_b1_Espera_default(handle);
}

/* Default react sequence for initial entry  */
static void stm_react_main_region_Programa_b2__entry_Default(Stm* handle)
{
	/* Default react sequence for initial entry  */
	stm_enseq_main_region_Programa_b2_Espera_default(handle);
}

/* Default react sequence for initial entry  */
static void stm_react_main_region_Programa_b3__entry_Default(Stm* handle)
{
	/* Default react sequence for initial entry  */
	stm_enseq_main_region_Programa_b3_Espera_default(handle);
}

/* Default react sequence for initial entry  */
static void stm_react_main_region_Programa_Color__entry_Default(Stm* handle)
{
	/* Default react sequence for initial entry  */
	stm_enseq_main_region_Programa_Color_Detenido_default(handle);
}

/* Default react sequence for initial entry  */
static void stm_react_main_region__entry_Default(Stm* handle)
{
	/* Default react sequence for initial entry  */
	stm_enseq_main_region_Programa_default(handle);
}


