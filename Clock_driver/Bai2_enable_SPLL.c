/**
 * @file    main.c
 * @brief   Main function for SPLL (System PLL) initialization
 * @details This file contains the main function that initializes the System PLL (SPLL) to 160 MHz.
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

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief   Initializes the System PLL (SPLL) to 160 MHz.
 * @details This function first ensures the system oscillator (SOSC) is running at 8 MHz by calling `SOC_init_8Mhz()`.
 *          It then configures the SPLL to operate at 160 MHz by setting the appropriate clock dividers and 
 *          configuration values. The function waits until the SPLL is valid.
 *
 * @return  void
 */
void SPLL_init_160Mhz(void)
{     
    /* Initialize the system oscillator to 8 MHz */
    SOC_init_8Mhz();
    
    /* Ensure SPLLCSR register is unlocked */
    while (SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK)
    {
        SCG->SPLLCSR = 0x00000000;  /* Disable SPLL by setting SPLLEN to 0 */
    }
    
    /* Set SPLL Clock Dividers */
    SCG->SPLLDIV = 0x00000302;  /* SPLLDIV1 divide by 2, SPLLDIV2 divide by 4 */
    
    /* Configure the SPLL */
    SCG->SPLLCFG = 0x00080000;
    /*
     * PREDIV = 0: Divide SOSC_CLK by 0 + 1 = 1
     * MULT = 01000 (24): Multiply system PLL by 16 + 24 = 40
     * SPLL_CLK = ((8 MHz / 1) * 40) / 2 = 160 MHz
     */
    
    /* Ensure SPLLCSR register is unlocked again */
    while (SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK)
    {
        SCG->SPLLCSR = 0x00000001;  /* Enable SPLL by setting SPLLEN to 1 */
    }
    
    /* Wait for SPLL to be valid */
    while (!(SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD_MASK))
    {
        /* Do nothing, just wait */
    }
}
