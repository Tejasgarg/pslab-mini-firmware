/**
 * @file adc.c
 * @brief Hardware-independent ADC (Analog-to-Digital Converter) implementation
 * 
 * This module provides the hardware-independent layer of the ADC driver.
 * It manages ADC initialization, configuration, and data acquisition.
 * The implementation relies on hardware-specific functions defined in
 * src/system/h563xx/adc_ll.c (or equivalent for other platforms).  
 * 
 * @author Tejas Garg
 * @date 2025-07-02
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h> 

#include "adc.h"
#include "adc_ll.h"
#include "bus.h"

/**
 * @brief Initializes the ADC peripheral.
 * 
 * This function initializes the ADC peripheral with the specified settings.
 * It must be called before any ADC operations can be performed.
 * 
 * @param hadc Pointer to the ADC handle structure.
 * @return HAL_StatusTypeDef Status of the operation.
 */
HAL_StatusTypeDef ADC_Init(ADC_HandleTypeDef *hadc)
{
    if (!hadc) {
        return HAL_ERROR;
    }       
    // Initialize the ADC peripheral
    return ADC1_LL_Init(hadc);
}

/**
 * @brief Deinitializes the ADC peripheral.
 * 
 * This function deinitializes the ADC peripheral and releases any resources used.
 * It should be called when the ADC is no longer needed.
 * 
 * @param hadc Pointer to the ADC handle structure.
 */
void ADC_DeInit(ADC_HandleTypeDef *hadc)
{
    if (!hadc) {    
        return;
    }
    // Deinitialize the ADC peripheral
    ADC1_LL_DeInit(hadc);
}

/**
 * @brief Starts the ADC conversion.
 * 
 * This function starts the ADC conversion process. It must be called after
 * the ADC has been initialized and configured.
 * 
 * @param hadc Pointer to the ADC handle structure.
 * @return HAL_StatusTypeDef Status of the operation.
 */
HAL_StatusTypeDef ADC_Start(ADC_HandleTypeDef *hadc)
{
    if (!hadc) {
        return HAL_ERROR;   
    }
    // Start the ADC conversion
    return ADC1_Start(hadc);
}

/**
 * @brief Stops the ADC conversion.
 * 
 * This function stops the ongoing ADC conversion process. It can be called
 * to halt conversions before deinitializing the ADC or when no longer needed.
 * 
 * @param hadc Pointer to the ADC handle structure.
 * @return HAL_StatusTypeDef Status of the operation.
 */
HAL_StatusTypeDef ADC_Stop(ADC_HandleTypeDef *hadc)
{
    if (!hadc) {
        return HAL_ERROR;   
    }
    // Stop the ADC conversion
    return ADC1_Stop(hadc);
}