/**
*   @file    gpio_register.h
*   @brief   GPIO Register Definitions
*   @details This file contains the GPIO register layout typedef and base address definitions.
*/

/*==================================================================================================

==================================================================================================*/
#ifndef GPIO_REGISTER_H
#define GPIO_REGISTER_H

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
/**
* @brief   GPIO - Register Layout Typedef
* @details This structure defines the register layout for GPIO peripherals.
*/
typedef struct {
    volatile unsigned int PDOR;   /*!< Port Data Output Register */
    volatile unsigned int PSOR;   /*!< Port Set Output Register */
    volatile unsigned int PCOR;   /*!< Port Clear Output Register */
    volatile unsigned int PTOR;   /*!< Port Toggle Output Register */
    volatile const unsigned int PDIR;   /*!< Port Data Input Register */
    volatile unsigned int PDDR;   /*!< Port Data Direction Register */
    volatile unsigned int PIDR;   /*!< Port Input Disable Register */
} GPIO_Type;

/* Peripheral GPIO base addresses */
#define GPIO_D_BASE (0x400FF0C0u)   /*!< Base address for GPIO Port D */
#define GPIO_E_BASE (0x400FF100u)   /*!< Base address for GPIO Port E */
#define GPIO_C_BASE (0x400FF080u)   /*!< Base address for GPIO Port C */
#define GPIO_B_BASE (0x400FF040u)   /*!< Base address for GPIO Port B */
#define GPIO_A_BASE (0x400FF000u)   /*!< Base address for GPIO Port A */

/* Peripheral GPIO base pointers */
#define GPIOD ((GPIO_Type *)GPIO_D_BASE)   /*!< GPIO Port D base pointer */
#define GPIOE ((GPIO_Type *)GPIO_E_BASE)   /*!< GPIO Port E base pointer */
#define GPIOC ((GPIO_Type *)GPIO_C_BASE)   /*!< GPIO Port C base pointer */
#define GPIOB ((GPIO_Type *)GPIO_B_BASE)   /*!< GPIO Port B base pointer */
#define GPIOA ((GPIO_Type *)GPIO_A_BASE)   /*!< GPIO Port A base pointer */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* GPIO_REGISTER_H */
