/**
 * @file    nvic.c
 * @brief   Main function for NVIC Driver Function
 * @details This file contains the main function of NVIC includes: 
 *                                                              enable interupt, disable interupt
 *                                                              clear pending and set priority
 */

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include "nvic.h"

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
 * @brief   Enable NVIC interrupt for the specified IRQ number
 * @param   IRQ_number: The IRQ number to enable
 * @return  void
 */
void NVIC_EnableInterrupt(IRQn_Type IRQ_number) {
    NVIC->NVIC_ISER[IRQ_number >> 5] |= (1 << (IRQ_number & 0x1F));
}

/**
 * @brief   Disable NVIC interrupt for the specified IRQ number
 * @param   IRQ_number: The IRQ number to disable
 * @return  void
 */
void NVIC_DisableInterrupt(IRQn_Type IRQ_number) {
    NVIC->NVIC_ICER[IRQ_number >> 5] |= (1 << (IRQ_number & 0x1F));
}

/**
 * @brief   Clear pending flag for the specified IRQ number
 * @param   IRQ_number: The IRQ number to clear pending flag
 * @return  void
 */
void NVIC_ClearPendingFlag(IRQn_Type IRQ_number) {
    NVIC->NVIC_ISPR[IRQ_number >> 5] |= (1 << (IRQ_number & 0x1F));
}

/**
 * @brief   Set priority for the specified IRQ number
 * @param   IRQ_number: The IRQ number to set priority
 * @param   priority: The priority value to set (0-255)
 * @return  void
 */
void NVIC_SetPriority(IRQn_Type IRQ_number, unsigned char priority) {
    priority <<= 4;
    NVIC->NVIC_IPR[IRQ_number >> 2] |= (priority << ((IRQ_number & 3UL) << 3U));
}
