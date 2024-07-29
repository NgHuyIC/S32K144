/**
 * @file    bai4_HSRUN_mode.c
 * @brief   Main function for clock configuration in High-Speed Run mode
 * @details This file contains functions to initialize the System PLL to 112 MHz and configure the SCG 
 *          to use this clock source in High-Speed Run mode.
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
static void SPLL_init_112Mhz(void);

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @brief   Initializes the System PLL to 112 MHz.
 * @details This function configures the SPLL to generate a clock frequency of 112 MHz.
 *          It unlocks the SPLLCSR register if it is locked, sets the SPLLDIV and SPLLCFG registers,
 *          and waits until the SPLL clock is valid.
 *
 * @return  void
 */
static void SPLL_init_112Mhz(void)
{   
    /* Ensure SPLLCSR register is unlocked */
    while (SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK)
    {
        SCG->SPLLCSR = 0x00000000;  /* Disable SPLL if it's locked */
    }
    
    /* Configure SPLL Dividers */
    SCG->SPLLDIV = 0x00000302;  /* SPLLDIV1 divide by 2, SPLLDIV2 divide by 4 */
    
    /* Configure SPLL Settings */
    SCG->SPLLCFG = 0x00180100;
    /*
     * PREDIV = 1: Divide SOSC_CLK by 2
     * MULT = 11000 (40): Multiply system PLL by 16+40=56
     * SPLL_CLK = ((8MHz / 2) * 56) / 2 = 112 MHz
     */
    
    /* Ensure SPLLCSR register is unlocked again */
    while (SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK)
    {
        SCG->SPLLCSR = 0x00000001;  /* Enable SPLL */
    }
    
    /* Wait for SPLL to become valid */
    while (!(SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD_MASK))
    {
        /* Do nothing, just wait */
    }
}

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief   Configures the system clock to 112 MHz in High-Speed Run mode.
 * @details This function initializes the System PLL to 112 MHz using the `SPLL_init_112Mhz()` function.
 *          It then configures the SCG to use the system PLL as the clock source and sets the core, bus,
 *          and slow clock dividers to achieve a 112 MHz system clock.
 *
 * @return  void
 */
void HSRUNmode_112MHz(void)
{   
    /* Initialize the System PLL to 112 MHz */
    SPLL_init_112Mhz();
    
    /* Configure the SCG to use the system PLL and set clock dividers */
    SCG->HCCR = 0x06000013;
    /*
     * SCS = 0110: System PLL (SPLL_CLK) is the system clock source
     * DIVCORE = 0000: Divide core clock by 1
     * DIVBUS = 0001: Divide bus clock by 2
     * DIVSLOW = 0011: Divide slow clock by 4
     */
    
    /* Wait for the system clock source to be set to SPLL */
    while (((SCG->CSR & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT) != 6)
    {
        /* Do nothing, just wait */
    }
}
