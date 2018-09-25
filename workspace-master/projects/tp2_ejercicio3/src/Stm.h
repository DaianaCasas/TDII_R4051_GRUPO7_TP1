
#ifndef STM_H_
#define STM_H_

#include "sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'stm'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Stm_main_region_Programa,
	Stm_main_region_Programa_b1_Espera,
	Stm_main_region_Programa_b1_Presiona,
	Stm_main_region_Programa_b1_Presionado,
	Stm_main_region_Programa_b2_Espera,
	Stm_main_region_Programa_b2_Presiona,
	Stm_main_region_Programa_b2_Presionado,
	Stm_main_region_Programa_b3_Espera,
	Stm_main_region_Programa_b3_Presiona,
	Stm_main_region_Programa_b3_Presionado,
	Stm_main_region_Programa_Color_Detenido,
	Stm_main_region_Programa_Color_Iniciar,
	Stm_main_region_Programa_Color_Invertir,
	Stm_last_state
} StmStates;

/*! Type definition of the data structure for the StmIface interface scope. */
typedef struct
{
	sc_boolean bBoton1;
	sc_boolean bBoton2;
	sc_boolean bBoton3;
	sc_boolean eTic_raised;
	sc_boolean eTime_raised;
} StmIface;

/*! Type definition of the data structure for the StmInternal interface scope. */
typedef struct
{
	sc_integer tic1;
	sc_integer tic2;
	sc_integer tic3;
	sc_boolean eBoton1_raised;
	sc_boolean eBoton2_raised;
	sc_boolean eBoton3_raised;
	sc_integer color_num;
} StmInternal;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define STM_MAX_ORTHOGONAL_STATES 4

/*! 
 * Type definition of the data structure for the Stm state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	StmStates stateConfVector[STM_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	StmIface iface;
	StmInternal internal;
} Stm;

/*! Initializes the Stm state machine data structures. Must be called before first usage.*/
extern void stm_init(Stm* handle);

/*! Activates the state machine */
extern void stm_enter(Stm* handle);

/*! Deactivates the state machine */
extern void stm_exit(Stm* handle);

/*! Performs a 'run to completion' step. */
extern void stm_runCycle(Stm* handle);


/*! Gets the value of the variable 'bBoton1' that is defined in the default interface scope. */ 
extern sc_boolean stmIface_get_bBoton1(const Stm* handle);
/*! Sets the value of the variable 'bBoton1' that is defined in the default interface scope. */ 
extern void stmIface_set_bBoton1(Stm* handle, sc_boolean value);
/*! Gets the value of the variable 'bBoton2' that is defined in the default interface scope. */ 
extern sc_boolean stmIface_get_bBoton2(const Stm* handle);
/*! Sets the value of the variable 'bBoton2' that is defined in the default interface scope. */ 
extern void stmIface_set_bBoton2(Stm* handle, sc_boolean value);
/*! Gets the value of the variable 'bBoton3' that is defined in the default interface scope. */ 
extern sc_boolean stmIface_get_bBoton3(const Stm* handle);
/*! Sets the value of the variable 'bBoton3' that is defined in the default interface scope. */ 
extern void stmIface_set_bBoton3(Stm* handle, sc_boolean value);
/*! Raises the in event 'eTic' that is defined in the default interface scope. */ 
extern void stmIface_raise_eTic(Stm* handle);

/*! Raises the in event 'eTime' that is defined in the default interface scope. */ 
extern void stmIface_raise_eTime(Stm* handle);


/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean stm_isActive(const Stm* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean stm_isFinal(const Stm* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean stm_isStateActive(const Stm* handle, StmStates state);

#ifdef __cplusplus
}
#endif 

#endif /* STM_H_ */
