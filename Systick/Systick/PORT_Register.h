/**
* @file    port_register.h
* @brief   PORT Register Definitions
* @details This file contains the PCC register layout typedef and base address definitions for GPIO peripherals.
*/

#ifndef PORT_REGISTER_H
#define PORT_REGISTER_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define PORT_PCR_MUX_SHIFT                   8u
#define PORT_PCR_MUX_MASK                   0x700u
#define PORT_PCR_MUX(x)    (((unsigned int)((unsigned int)(x) << PORT_PCR_MUX_SHIFT)) & PORT_PCR_MUX_MASK)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** GPIO - Register Layout Typedef */
typedef struct {
    volatile unsigned int PCR[32]; /**< Pin Control Registers */
} PORT_Type;

/** Peripheral base addresses for GPIO ports */
#define PORTD_BASE   (0x4004C000u) /**< Base address for Port D */
#define PORTE_BASE   (0x4004D000u) /**< Base address for Port E */
#define PORTC_BASE   (0x4004B000u) /**< Base address for Port C */
#define PORTB_BASE   (0x4004A000u) /**< Base address for Port B */
#define PORTA_BASE   (0x40049000u) /**< Base address for Port A */

/** Peripheral base pointers */
#define PORTD    ((PORT_Type *)PORTD_BASE) /**< Pointer to Port D registers */
#define PORTE    ((PORT_Type *)PORTE_BASE) /**< Pointer to Port E registers */
#define PORTC    ((PORT_Type *)PORTC_BASE) /**< Pointer to Port C registers */
#define PORTB    ((PORT_Type *)PORTB_BASE) /**< Pointer to Port B registers */
#define PORTA    ((PORT_Type *)PORTA_BASE) /**< Pointer to Port A registers */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* PORT_REGISTER_H */
