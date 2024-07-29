/**
 * @file    scg_register.h
 * @brief   SCG (System Clock Generator) Register Definitions
 * @details This file contains register definitions for the SCG module, including macros and structures
 *          for accessing and manipulating the SCG hardware registers.
 */

/*==================================================================================================

==================================================================================================*/
#ifndef SCG_REGISTER_H
#define SCG_REGISTER_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** Peripheral SCG base address */
#define SCG_BASE                        (0x40064000u)

/** Peripheral SCG base pointer */
#define SCG                      ((SCG_Type *)SCG_BASE)
///////////////////////////////////////////////////
#define SCG_SPLLCSR_LK_MASK                      0x800000u
#define SCG_SOSCCSR_LK_MASK                      0x800000u
#define SCG_SOSCCSR_SOSCVLD_MASK                 0x1000000u
#define SCG_SPLLCSR_SPLLVLD_MASK                 0x1000000u
#define SCG_CSR_SCS_MASK                         0xF000000u
#define SCG_CSR_SCS_SHIFT                        24u

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief          SCG - Register Layout Typedef
 * @details        This structure defines the layout of the SCG hardware registers.
 */
typedef struct {
    volatile unsigned int VERID;       /**< Offset: 0x0  Version Identification Register */
    volatile unsigned int PARAM;       /**< Offset: 0x4  Parameter Register */
    volatile unsigned int RESERVED_0[8];
    volatile unsigned int CSR;         /**< Offset: 0x10 Clock Status Register */
    volatile unsigned int RCCR;        /**< Offset: 0x14 Run Clock Control Register */
    volatile unsigned int VCCR;        /**< Offset: 0x18 Voltage and Clock Control Register */
    volatile unsigned int HCCR;        /**< Offset: 0x1C HSR Clock Control Register */
    volatile unsigned int CLKOUTCNFG;  /**< Offset: 0x20 Clock Output Configuration Register */
    volatile unsigned int RESERVED_1[220];
    volatile unsigned int SOSCCSR;     /**< Offset: 0x100 SOSC Control Status Register */
    volatile unsigned int SOSCDIV;     /**< Offset: 0x104 SOSC Divider Register */
    volatile unsigned int SOSCCFG;     /**< Offset: 0x108 SOSC Configuration Register */
    volatile unsigned int RESERVED_2[244];
    volatile unsigned int SIRCCSR;     /**< Offset: 0x200 SIRC Control Status Register */
    volatile unsigned int SIRCDIV;     /**< Offset: 0x204 SIRC Divider Register */
    volatile unsigned int SIRCCFG;     /**< Offset: 0x208 SIRC Configuration Register */
    volatile unsigned int RESERVED_3[244];
    volatile unsigned int FIRCCSR;     /**< Offset: 0x300 FIRC Control Status Register */
    volatile unsigned int FIRCDIV;     /**< Offset: 0x304 FIRC Divider Register */
    volatile unsigned int FIRCCFG;     /**< Offset: 0x308 FIRC Configuration Register */
    volatile unsigned int RESERVED_4[756];
    volatile unsigned int SPLLCSR;     /**< Offset: 0x600 SPLL Control Status Register */
    volatile unsigned int SPLLDIV;     /**< Offset: 0x604 SPLL Divider Register */
    volatile unsigned int SPLLCFG;     /**< Offset: 0x608 SPLL Configuration Register */
} SCG_Type;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#endif