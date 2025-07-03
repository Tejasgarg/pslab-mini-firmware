/**
 * @file adc_ll.h
 * @brief Hardware-specific ADC (Analog-to-Digital Converter) interface
 * 
 * This header file defines the hardware-specific interface for the ADC driver.
 * 
 * @author Tejas Garg
 * @date 2025-07-02
 */
#ifndef ADC_LL_H
#define ADC_LL_H    

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Initializes the ADC1 peripheral.
 * 
 * This function configures the ADC1 peripheral with the specified settings.
 * 
 * @param hadc Pointer to the ADC handle structure.
 */
void ADC1_LL_Init(ADC_HandleTypeDef *hadc);

/**
 * @brief Deinitializes the ADC peripheral.
 * 
 * This function deinitializes the ADC peripheral and releases any resources used.
 * 
 * @param hadc Pointer to the ADC handle structure.
 */
void HAL_ADC_LL_DeInit(ADC_HandleTypeDef *hadc);

/**
 * @brief Starts the ADC conversion.
 * 
 * This function starts the ADC conversion process. It must be called after
 * the ADC has been initialized and configured.
 * 
 * @param hadc Pointer to the ADC handle structure.
 * @return HAL_StatusTypeDef Status of the operation.
 */
HAL_StatusTypeDef ADC1_Start(ADC_HandleTypeDef *hadc);

/**
 * @brief Stops the ADC conversion.
 * 
 * This function stops the ongoing ADC conversion process. It can be called
 * to halt conversions before deinitializing the ADC or when no longer needed.
 * 
 * @param hadc Pointer to the ADC handle structure.
 * @return HAL_StatusTypeDef Status of the operation.
 */
HAL_StatusTypeDef ADC1_Stop(ADC_HandleTypeDef *hadc);

#endif // ADC_LL_H
