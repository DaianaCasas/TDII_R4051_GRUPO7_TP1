/* Copyright 2016
 * All rights reserved.
 *
 * This file is part of lpc1769_template.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.*/


/*==================[inclusions]=============================================*/

#include "../../tp2_ejercicio3/inc/main.h"

#include "../../tp2_ejercicio3/inc/FreeRTOSConfig.h"
#include "StmRequired.h"
#include "Stm.h"
#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/*==================[macros and definitions]=================================*/

// puerto,pin
#define ROJO 	2,1		//PWM2 P2[1]
#define AZUL	2,2		//PWM1 P2[2]
#define VERDE	2,3    // PWM0 P2[3]

#define PULSADOR_1	2,10	// Teclado5x1_0 P2[10] -- OK
#define PULSADOR_2	0,18	// Teclado5x1_1 P0[18] -- OK
#define PULSADOR_3	0,11	// Teclado5x1_2 P0[11] -- no es el 3 en la placa
#define PULSADOR_4  2,13	// Teclado5x1_3 P2[13] -- OK
#define PULSADOR_5  1,26	// Teclado5x1_4 P1[26] -- ED0

#define	P1 1
#define	P2 2
#define	P3 3

#define COLOR_1	1
#define COLOR_2	2
#define COLOR_3	3
#define COLOR_4	4
#define COLOR_5	5
#define COLOR_6	6
#define COLOR_7	7

/*==================[internal data declaration]==============================*/
#define REFRESH_COLOR_ms 350
#define TIEMPO_DE_DIAGNOSTICO_ms 2000
#define TIEMPO_DE_DEBOUNCE_ms 20

/*==================[internal functions declaration]=========================*/

static void initHardware(void);
int LeerPulsador( int num);
/*==================[internal data definition]===============================*/
 int tiempo_de_diagnostico = TIEMPO_DE_DIAGNOSTICO_ms;
 int tiempo_tic_debounce = TIEMPO_DE_DEBOUNCE_ms;
 int tiempo_refresh_color = REFRESH_COLOR_ms;

/*==================[external data definition]===============================*/
#define mainQUEUE_LENGTH					( 5 )

/*==================[internal functions definition]==========================*/

void stmIface_setColor(const Stm* handle, const sc_integer estado)
{
	switch( estado)
	{
		case COLOR_1:
			Chip_GPIO_SetPinOutLow(LPC_GPIO,ROJO);
			Chip_GPIO_SetPinOutLow(LPC_GPIO,VERDE);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO,AZUL);
		break;

		case COLOR_2:
			Chip_GPIO_SetPinOutLow(LPC_GPIO,ROJO);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO,VERDE);
			Chip_GPIO_SetPinOutLow(LPC_GPIO,AZUL);
		break;

		case COLOR_3:
			Chip_GPIO_SetPinOutLow(LPC_GPIO,ROJO);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO,VERDE);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO,AZUL);
		break;

		case COLOR_4:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO,ROJO);
			Chip_GPIO_SetPinOutLow(LPC_GPIO,VERDE);
			Chip_GPIO_SetPinOutLow(LPC_GPIO,AZUL);
		break;

		case COLOR_5:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO,ROJO);
			Chip_GPIO_SetPinOutLow(LPC_GPIO,VERDE);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO,AZUL);
		break;

		case COLOR_6:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO,ROJO);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO,VERDE);
			Chip_GPIO_SetPinOutLow(LPC_GPIO,AZUL);
		break;

		case COLOR_7:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO,ROJO);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO,VERDE);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO,AZUL);
		break;
	}
}

static void initHardware(void)
{
	SystemCoreClockUpdate();

	   Board_Init();
	   // Chip_GPIO_SetPinDirOutput(LPC_GPIO, num_puerto, num_pin);
	   // Chip_GPIO_SetPinDirInput(LPC_GPIO, num_puerto, num_pin);
	   // Chip_GPIO_GetPinState(LPC_GPIO, num_puerto, num_pin);
	    Chip_IOCON_PinMuxSet(LPC_IOCON,AZUL,FUNC0);
	    Chip_IOCON_PinMuxSet(LPC_IOCON,ROJO,FUNC0);
	    Chip_IOCON_PinMuxSet(LPC_IOCON,VERDE,FUNC0);

		Chip_IOCON_PinMuxSet(LPC_IOCON,PULSADOR_1, FUNC0); /* GPIO0[4], SW1 */
		Chip_IOCON_PinMuxSet(LPC_IOCON,PULSADOR_2, FUNC0); /* GPIO0[8], SW2*/
		Chip_IOCON_PinMuxSet(LPC_IOCON,PULSADOR_4, FUNC0); /* GPIO0[9], SW3*/


	    Chip_GPIO_SetPinDIROutput(LPC_GPIO,AZUL); 	//Azul
	    Chip_GPIO_SetPinDIROutput(LPC_GPIO,ROJO); 	// Rojo
	    Chip_GPIO_SetPinDIROutput(LPC_GPIO,VERDE); 	// Verde

	    Chip_GPIO_SetPinDIRInput(LPC_GPIO,PULSADOR_1); // Pulsador 1
	    Chip_GPIO_SetPinDIRInput(LPC_GPIO,PULSADOR_2); // Pulsador 2
	    Chip_GPIO_SetPinDIRInput(LPC_GPIO,PULSADOR_4); // Pulsador 3
}

int LeerPulsador( int num)
{	int estado=0;
	switch(num)
	{
		case P1:
			estado = Chip_GPIO_ReadPortBit(LPC_GPIO, PULSADOR_1);
		break;
		case P2:
			estado = Chip_GPIO_ReadPortBit(LPC_GPIO, PULSADOR_2);
		break;
		case P3:
			estado = Chip_GPIO_ReadPortBit(LPC_GPIO, PULSADOR_4);
		break;
	}
	return (estado)?0:1;
}
void Diagnostico(void *pvParameters)
{

	//	vPrint("Comienza el diagnostico\n")
	//Loop infinito
	while(1)
	{
		//IMPORTANTE:
		//Este loop pretende simular un conjunto de funciones que
		//insumen un tiempo para realizar el diagnostico del equipo
		//Pero NO es aceptable tener al micro dentro de esta tarea
		//haciendo nada, esto es solo un ejemplo.
		if(!tiempo_de_diagnostico)
		{
			//vPrintString("Termina el diagnostico\n");
			Board_LED_Set(0, 1);
			vTaskDelay(TIEMPO_DE_DIAGNOSTICO_ms/portTICK_RATE_MS);
			tiempo_de_diagnostico = TIEMPO_DE_DIAGNOSTICO_ms;
			Board_LED_Set(0, 0);
			//vPrintString("Comienza el diagnostico\n");
		}
	}

}

void JuegoDeLuces ( void *pvParameters )
{
	Stm statechart;
	stm_init(&statechart);
	stm_enter(&statechart);
	tiempo_refresh_color=REFRESH_COLOR_ms;

		while(1)
		{
			stmIface_set_bBoton1(&statechart,LeerPulsador(P1));
			stmIface_set_bBoton2(&statechart,LeerPulsador(P3));
			stmIface_set_bBoton3(&statechart,LeerPulsador(P2));
			stmIface_raise_eTic(&statechart);
			if(!--tiempo_refresh_color)
			{
				stmIface_raise_eTime(&statechart);
				tiempo_refresh_color=REFRESH_COLOR_ms;
			}
			stm_runCycle(&statechart);
			vTaskDelay(2);

		}
}
int main(void) {
	//Incialización del Hardware
	initHardware();
	//Creación de las tareas
	// xTaskCreate( pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxCreatedTask )
	xTaskCreate(	JuegoDeLuces, (signed portCHAR* )
					"Luces",
					configMINIMAL_STACK_SIZE,
					NULL,
					tskIDLE_PRIORITY+2,
					NULL );

	xTaskCreate(	Diagnostico, ( signed portCHAR* )
					"Diag",
					configMINIMAL_STACK_SIZE,
					NULL,
					tskIDLE_PRIORITY+1,
					NULL );
	//Inicio el Scheduler
	vTaskStartScheduler();
	// Enter an infinite loop, just incrementing a counter
	volatile static int i = 0 ;
	while(1) {
		i++ ;
	}
	return 0 ;
}

void vApplicationTickHook ( void )
{
	if(tiempo_de_diagnostico)
		tiempo_de_diagnostico--;
}
void vApplicationIdleHook ( void )
{
	__ASM volatile ("wfi");
}
