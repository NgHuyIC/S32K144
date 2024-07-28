/**
*   @file    PCC.h
*   @brief   PCC Initialization and Control Functions
*   @details This file contains the API for initializing and controlling GPIO pins.
*/

/*==================================================================================================
==================================================================================================*/
#ifndef PCC_H
#define PCC_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "PCC_Registers.h"

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief   GPIO Configuration Structure
* @details This structure holds the configuration for initializing GPIO pins.
*/
typedef struct
{
    GPIO_Type *base;           /*!< GPIO base pointer. */
    unsigned char GPIO_PinNumber; /*!< Pin number. */
    unsigned char GPIO_PinMode;   /*!< Pin mode. */
} Gpio_ConfigType;
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
 * @brief Initializes the pins with the given configuration structure.
 *
 * This function configures the pins with the options provided in the
 * given configuration structure.
 *
 * @param[in] ConfigPtr: The configuration structure
 * @return None
 */
void Gpio_Init(const Gpio_ConfigType* ConfigPtr);

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

#endif /* PCC_H */
