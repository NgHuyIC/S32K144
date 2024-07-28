/**
* @file    demo.c
* @brief   Demo for GPIO Initialization and Control
* @details This file demonstrates the usage of GPIO functions to control LEDs and handle button interrupts.
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Gpio.h"
#include <stddef.h> // For NULL definition

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

/*!
 * @brief Initializes a GPIO pin based on configuration.
 *
 * This function configures the pin mode of a GPIO pin.
 *
 * @param[in] base Pointer to the GPIO peripheral structure.
 * @param[in] pinNumber Pin number to configure.
 * @param[in] pinMode Pin mode: 0 for INPUT, 1 for OUTPUT.
 * @return None
 */
void Gpio_Init(GPIO_Type *base, unsigned char pinNumber, unsigned char pinMode)
{
    if (base == NULL)
    {
        return; // Exit if base pointer is NULL
    }

    if (pinMode == 1)
    {
        // Set pin as OUTPUT
        base->PDDR |= (1u << pinNumber);
    }
    else if (pinMode == 0)
    {
        // Set pin as INPUT
        base->PDDR &= ~(1u << pinNumber);
    }
}

/*!
 * @brief Writes a value to the specified output pin.
 *
 * This function writes a value (0 or 1) to the specified output pin.
 *
 * @param[in] pGPIOx Pointer to the GPIO peripheral structure.
 * @param[in] PinNumber Pin number to write to.
 * @param[in] value Value to write (0 or 1).
 * @return None
 */
void GPIO_WriteToOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber, unsigned char value)
{
    if (value == 1)
    {
        // Set the pin HIGH
        pGPIOx->PDOR |= (1u << PinNumber);
    }
    else if (value == 0)
    {
        // Set the pin LOW
        pGPIOx->PDOR &= ~(1u << PinNumber);
    }
}

/*!
 * @brief Sets the specified output pin to HIGH.
 *
 * This function sets the specified output pin to HIGH.
 *
 * @param[in] pGPIOx Pointer to the GPIO peripheral structure.
 * @param[in] PinNumber Pin number to set HIGH.
 * @return None
 */
void GPIO_SetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    pGPIOx->PDOR |= (1u << PinNumber);
}

/*!
 * @brief Resets the specified output pin to LOW.
 *
 * This function resets the specified output pin to LOW.
 *
 * @param[in] pGPIOx Pointer to the GPIO peripheral structure.
 * @param[in] PinNumber Pin number to reset LOW.
 * @return None
 */
void GPIO_ResetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    pGPIOx->PDOR &= ~(1u << PinNumber);
}

/*!
 * @brief Toggles the state of the specified output pin.
 *
 * This function toggles the state of the specified output pin.
 *
 * @param[in] pGPIOx Pointer to the GPIO peripheral structure.
 * @param[in] PinNumber Pin number to toggle.
 * @return None
 */
void GPIO_ToggleOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    pGPIOx->PDOR ^= (1u << PinNumber);
}

/*!
 * @brief Reads the current state of the specified input pin.
 *
 * This function reads the current state (0 or 1) of the specified input pin.
 *
 * @param[in] pGPIOx Pointer to the GPIO peripheral structure.
 * @param[in] PinNumber Pin number to read from.
 * @return The current state of the pin (0 or 1).
 */
unsigned char GPIO_ReadFromInputPin(GPIO_Type *pGPIOx, unsigned char PinNumber)
{
    unsigned char value = (pGPIOx->PDIR >> PinNumber) & 0x01;
    return value;
}


