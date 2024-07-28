/**
 * @file    GPIO.h
 * @brief   GPIO Initialization and Control Functions
 * @details This file contains the API for initializing and controlling GPIO pins.
 */

#ifndef GPIO_H
#define GPIO_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Gpio_Registers.h" /**< Include the GPIO register definitions */

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

/**
 * @brief Initializes the GPIO pins with the given configuration.
 *
 * This function initializes the GPIO pins based on the provided configuration structure.
 *
 * @param[in] base: Pointer to the GPIO base peripheral.
 * @param[in] pinNumber: Pin number to initialize.
 * @param[in] pinMode: Mode to configure for the pin (input, output, etc.).
 * @return None
 */
void Gpio_Init(GPIO_Type *base, unsigned char pinNumber, unsigned char pinMode);

/**
 * @brief Writes a value to the specified output pin.
 *
 * This function writes the given value to the specified output pin.
 *
 * @param[in] pGPIOx: Pointer to the GPIO peripheral.
 * @param[in] PinNumber: Pin number to write to.
 * @param[in] value: Value to write (0 or 1).
 * @return None
 */
void GPIO_WriteToOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber, unsigned char value);

/**
 * @brief Sets the specified output pin.
 *
 * This function sets the specified output pin to high.
 *
 * @param[in] pGPIOx: Pointer to the GPIO peripheral.
 * @param[in] PinNumber: Pin number to set.
 * @return None
 */
void GPIO_SetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);

/**
 * @brief Resets the specified output pin.
 *
 * This function sets the specified output pin to low.
 *
 * @param[in] pGPIOx: Pointer to the GPIO peripheral.
 * @param[in] PinNumber: Pin number to reset.
 * @return None
 */
void GPIO_ResetOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);

/**
 * @brief Toggles the specified output pin.
 *
 * This function toggles the state of the specified output pin.
 *
 * @param[in] pGPIOx: Pointer to the GPIO peripheral.
 * @param[in] PinNumber: Pin number to toggle.
 * @return None
 */
void GPIO_ToggleOutputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);

/**
 * @brief Reads the value from the specified input pin.
 *
 * This function reads the current state of the specified input pin.
 *
 * @param[in] pGPIOx: Pointer to the GPIO peripheral.
 * @param[in] PinNumber: Pin number to read from.
 * @return The current state of the pin (0 or 1).
 */
unsigned char GPIO_ReadFromInputPin(GPIO_Type *pGPIOx, unsigned char PinNumber);

#endif /* GPIO_H */
