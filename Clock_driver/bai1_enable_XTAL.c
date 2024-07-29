/**
 * @file    main.c
 * @brief   Main function for clock initialization
 * @details This file contains the main function that initializes the system oscillator to 8 MHz using SCG registers.
 */

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "SCG_Registers.h"
#include "Clock.h"

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void SOC_init_8Mhz(void);

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/
static void SOC_init_8Mhz(void)
{
    /* Ensure SOSCCSR is unlocked */
    while (SCG->SOSCCSR & SCG_SOSCCSR_LK_MASK)
    {
		/* Disable Lock Bit */
		SCG->SOSCCSR = 0x00000000;
    }
    /* Set SOSC Clock Dividers */
    SCG->SOSCDIV = 0x00000101;  /* Divide by 1 */
    
    /* Configure the SOSC */
    SCG->SOSCCFG = 0x00000024; 
    /*
     * Range = 10: Medium frequency (SOSC between 1MHz-8MHz)
     * HGO = 0: Low-gain
     * EREFS = 1: Crystal oscillator
     */
    
    /* Ensure SOSCCSR is unlocked again */
    while (SCG->SOSCCSR & SCG_SOSCCSR_LK_MASK)
    {
        /* Enable the SOSC and Lock bit, can't write to this register */
		SCG->SOSCCSR = 0x00000001;
		/*
		 * SOSCERR = 0: System OSC Clock Monitor is disabled
		 * SOSCSEL = 0: System OSC is not the system clock source
		 * SOSCVLD = 0: System OSC is not enabled/valid
		 * LK = 0: SOSCCSR can be written
		 * SOSCCMRE = 0: Clock Monitor generates interrupt when error is detected
		 * SOSCCM = 0: System OSC Clock Monitor is disabled
		 * SOSCEN = 1: System OSC is enabled
		 */
    
    } 
    /* Wait for the system OSC clock to be valid */
    while (!(SCG->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK))
    {
        /* Do nothing, just wait */
    }
}

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief   Main function
 * @details Initializes the system oscillator to 8 MHz and enters an infinite loop.
 *
 * @return  int
 */
int main(void)
{
    SOC_init_8Mhz();  /* Initialize system oscillator to 8 MHz */
    
    while (1)
    {
        /* Infinite loop, system clock is running */
    }
}
