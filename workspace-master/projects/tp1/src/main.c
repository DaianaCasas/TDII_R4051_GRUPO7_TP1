
/** @brief Este es el desarrollo del Trabajo Práctico 1.
 */

/** \addtogroup Cambio de frecuencia del blinky.
 ** @{ */

/*==================[inclusions]=============================================*/

#include "../../tp1/inc/main.h"
#include "board.h"
/** @brief macros and definitions
 *
 */
/*==================[macros and definitions]=================================*/
#define FREC_MAX 10			/*	Frecuencia maxima del parpadeo del LED	*/
#define FREC_MIN 1			/*	Frecuencia minima del parpadeo del LED	*/
#define PAUSE_FREC 5000		/*	Tiempo activo de cada frecuencia del parpadeo del LED	*/

/*==================[internal functions declaration]=========================*/

/** @brief hardware initialization function
 *	@return none
 */
static void initHardware(void);

/** @brief delay function
 * @param t desired milliseconds to wait
 */
static void pausems(uint32_t t);

/*==================[internal data definition]===============================*/

/** @brief used for delay counter */
static uint32_t pausems_count;
static uint32_t pausems_frec=0;

/*==================[internal functions definition]==========================*/

static void initHardware(void)
{
	Board_Init();
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);
}

static void pausems(uint32_t t)
{
	pausems_count = t;
	while (pausems_count != 0) {
		__WFI();
	}
}

/*==================[external functions definition]==========================*/

void SysTick_Handler(void)
{
	if(pausems_count > 0) pausems_count--;
	if(pausems_frec > 0) pausems_frec--;
}

int main(void)
{
	initHardware();
	uint32_t frecuencia=FREC_MIN;
	while (1)
	{
		if( pausems_frec == 0 )
		{
			if(FREC_MIN<= frecuencia && frecuencia<=FREC_MAX)
			{
				frecuencia++;
			}
			else
			{
				frecuencia=FREC_MIN;
			}
			pausems_frec=PAUSE_FREC;
		}

		Board_LED_Toggle(0);
		pausems( 1 /( frecuencia*0.002 ));
	}
}

/** @} doxygen end group definition */

/*==================[end of file]============================================*/
