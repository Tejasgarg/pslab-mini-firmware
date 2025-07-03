/**
 * @file adc.h
 * @brief Hardware-independent ADC (Analog-to-Digital Converter) interface
 * 
 * This header file defines the public API for the ADC driver.
 * It provides functions for initializing the ADC, configuring channels,
 * starting conversions, and reading ADC values.
 * 
 * This implementation relies on hardware-specific functions defined in
 * src/system/h563xx/adc_ll.c (or equivalent for other platforms).
 * @author Tejas Garg
 * @date 2025-07-02
 */

#ifndef ADC_H
#define ADC_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "bus.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief ADC Initialization function.
 * 
 * This function initializes the ADC peripheral with the specified settings.
 * It must be called before any ADC operations can be performed.
 * 
 * @param hadc Pointer to the ADC handle structure.
 * @return HAL_StatusTypeDef Status of the operation.
 */
HAL_StatusTypeDef ADC_Init(ADC_HandleTypeDef *hadc);

/**
 * @brief Deinitializes the ADC peripheral.
 * 
 * This function deinitializes the ADC peripheral and releases any resources used.
 * It should be called when the ADC is no longer needed.
 * 
 * @param hadc Pointer to the ADC handle structure.
 */
void ADC_DeInit(ADC_HandleTypeDef *hadc);

/**
 * @brief Starts the ADC conversion.
 * 
 * This function starts the ADC conversion process. It must be called after
 * the ADC has been initialized and configured.
 * 
 * @param hadc Pointer to the ADC handle structure.
 * @return HAL_StatusTypeDef Status of the operation.
 */
HAL_StatusTypeDef ADC_Start(ADC_HandleTypeDef *hadc);

/**
 * @brief Stops the ADC conversion.
 * 
 * This function stops the ongoing ADC conversion process. It can be called
 * to halt conversions before deinitializing the ADC or when no longer needed.
 * 
 * @param hadc Pointer to the ADC handle structure.
 * @return HAL_StatusTypeDef Status of the operation.
 */
HAL_StatusTypeDef ADC_Stop(ADC_HandleTypeDef *hadc);

#ifdef __cplusplus
}
#endif

#endif // ADC_H
