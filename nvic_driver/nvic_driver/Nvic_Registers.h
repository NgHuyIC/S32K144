/**
 * @file    NVIC_register.h
 * @brief   NVIC Register Definitions
 * @details This file contains register definitions and structures related to NVIC (Nested Vectored Interrupt Controller).
 */
/*==================================================================================================

==================================================================================================*/
#ifndef NVIC_REGISTER_H_
#define NVIC_REGISTER_H_

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/

/*==================================================================================================
 *                                      DEFINES AND MACROS
 ==================================================================================================*/

/**  NVIC base address */
#define NVIC_BASE                 (0xE000E100u)

/**  NVIC base pointer */
#define NVIC                      ((NVIC_Type *)NVIC_BASE)

/*==================================================================================================
 *                                             ENUMS
 ==================================================================================================*/

/*==================================================================================================
 *                                STRUCTURES AND OTHER TYPEDEFS
 ==================================================================================================*/

/** NVIC - Register Layout Typedef */
typedef struct {
    volatile unsigned int NVIC_ISER[8];   /**< Interrupt Set-Enable Registers */
    volatile unsigned int dummy0[24];     /**< Reserved space */
    volatile unsigned int NVIC_ICER[8];   /**< Interrupt Clear-Enable Registers */
    volatile unsigned int dummy1[24];     /**< Reserved space */
    volatile unsigned int NVIC_ISPR[8];   /**< Interrupt Set-Pending Registers */
    volatile unsigned int dummy2[24];     /**< Reserved space */
    volatile unsigned int NVIC_ICPR[8];   /**< Interrupt Clear-Pending Registers */
    volatile unsigned int dummy3[24];     /**< Reserved space */
    volatile unsigned int NVIC_IABR[8];   /**< Interrupt Active Bit Registers */
    volatile unsigned int dummy4[56];     /**< Reserved space */
    volatile unsigned int NVIC_IPR[60];   /**< Interrupt Priority Registers */
    volatile unsigned int NVIC_STIR;      /**< Software Trigger Interrupt Register */
} NVIC_Type;

/*==================================================================================================
 *                                GLOBAL VARIABLE DECLARATIONS
 ==================================================================================================*/

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
 ==================================================================================================*/

#endif /* NVIC_REGISTER_H_ */
