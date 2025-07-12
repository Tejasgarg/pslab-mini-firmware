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

#include "../timer/tim.h"
#include "adc.h"
#include "adc_ll.h"
#include "error.h"
#include "../logging.h"

/**********************************************************************
 * Macros
 **********************************************************************/

enum { ADC1_TIM = 0 }; // Timer used for ADC1 conversions
enum { ADC1_TIM_Frequency = 25000 }; // ADC1 timer frequency in Hz

static ADC_CompleteCallback g_adc_callback =
    nullptr; // Callback for ADC completion

void ADC_set_complete_callback(ADC_CompleteCallback callback)
{
    if (callback) {
        g_adc_callback = callback; // Set the ADC complete callback
    } else {
        g_adc_callback = NULL; // Clear the ADC complete callback
    }
}

static void adc_complete_callback(uint32_t value)
{
    if (g_adc_callback) {
        g_adc_callback(value
        ); // Call the user-defined callback with the ADC value
    }
}

/**
 * @brief Initializes the ADC peripheral.
 *
 * This function initializes the ADC peripheral with the specified settings.
 * It must be called before any ADC operations can be performed.
 *
 */
void ADC_init(void)
{
    // Initialize the timer used for ADC conversions
    TIM_init(
        ADC1_TIM, ADC1_TIM_Frequency
    ); // Set the timer frequency to 25000 Hz to enable sampling at 1KSPS
    /*
    Explanation for 25khz to achieve 1KSPS:
    The peripheral clock for the ADC is set to 250MHz.
    and at 25khz of timer frequency, the period and prescaler values are
    calculated as follows:
    - Prescaler = Default Prescaler Value = 0
    - Period = 10000 - 1 = 9999

    Also the ADC is running at 25khz
    and for 12 bit conversion, the ADC takes 12.5 clock cycles to complete SAR.
    and another 12.5 clock cycles for sampling time.
    So, the total time taken for one conversion is 25 clock cycles.
    Therefore, the ADC can perform 25000 / 25 = 1000 conversions per second
    (1KSPS). Hence, the timer frequency is set to 25khz to achieve 1KSPS
    sampling rate. This allows the ADC to sample at a rate of 1KSPS (1000
    samples per second). The timer is used to trigger the ADC conversions at
    this rate. The ADC will be configured to use this timer for triggering
    conversions.
    */
    // Initialize the ADC peripheral
    ADC_LL_init();
    // Set the ADC complete callback
    ADC_LL_set_complete_callback(adc_complete_callback);
    LOG_INFO("ADC initialized with timer frequency %d Hz", ADC1_TIM_Frequency);
}

/**
 * @brief Deinitializes the ADC peripheral.
 *
 * This function deinitializes the ADC peripheral and releases any resources
 * used. It should be called when the ADC is no longer needed.
 */
void ADC_deinit(void)
{
    TIM_stop(ADC1_TIM); // Stop the timer used for ADC conversions
    // Deinitialize the ADC peripheral
    ADC_LL_deinit();
}

/**
 * @brief Starts the ADC conversion.
 *
 * This function starts the ADC conversion process. It must be called after
 * the ADC has been initialized and configured.
 *
 */
void ADC_start(void)
{
    // Start the ADC conversion
    ADC_LL_start();

    TIM_start(
        ADC1_TIM, ADC1_TIM_Frequency
    ); // Start the timer for ADC conversions
    LOG_INFO("ADC started with timer frequency %d Hz", ADC1_TIM_Frequency);
}

/**
 * @brief Stops the ADC conversion.
 *
 * This function stops the ongoing ADC conversion process. It can be called
 * to halt conversions before deinitializing the ADC or when no longer needed.
 *
 */
void ADC_stop(void)
{
    TIM_stop(ADC1_TIM); // Stop the timer used for ADC conversions
    // Stop the ADC conversion
    ADC_LL_stop();
}
