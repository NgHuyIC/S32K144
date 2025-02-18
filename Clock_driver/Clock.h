/**
 * @file    Clock.h
 * @brief   Clock Configuration
 * @details This file contains definitions and function prototypes for clock initialization and configuration.
 */
/*==================================================================================================
==================================================================================================*/
#ifndef CLOCK_H
#define CLOCK_H
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
void SOC_init_8Mhz();
void SPLL_init_160Mhz();
void NormaRUNmode_80MHz();
void SPLL_init_112Mhz();
void HSRUNmode_112MHz();
void configure_CLKOUT();

#endif // CLOCK_H