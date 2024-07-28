/**
*   @file    pcc_register.h
*   @brief   PCC Register Definitions
*   @details This file contains the PCC register layout typedef and base address definitions for GPIO peripherals.
*/
/*==================================================================================================
==================================================================================================*/
#ifndef PCC_REGISTER_H
#define PCC_REGISTER_H

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
    volatile unsigned int PDOR;
    volatile unsigned int PSOR;
    volatile unsigned int PCOR;
    volatile unsigned int PTOR;
    volatile const unsigned int PDIR;
    volatile unsigned int PDDR;
    volatile unsigned int PIDR;
} PCC_Type;

/* Peripheral GPIO base addresses */
#define GPIOD_BASE (0x400FF0C0u)
#define GPIOE_BASE (0x400FF100u)
#define GPIOC_BASE (0x400FF080u)
#define GPIOB_BASE (0x400FF040u)
#define GPIOA_BASE (0x400FF000u)

/* Peripheral GPIO base pointers */
#define GPIOD ((PCC_Type *)GPIOD_BASE)
#define GPIOE ((PCC_Type *)GPIOE_BASE)
#define GPIOC ((PCC_Type *)GPIOC_BASE)
#define GPIOB ((PCC_Type *)GPIOB_BASE)
#define GPIOA ((PCC_Type *)GPIOA_BASE)
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* PCC_REGISTER_H */
