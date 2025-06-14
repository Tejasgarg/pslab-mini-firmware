add_executable(pslab-mini-firmware)

target_sources(pslab-mini-firmware
    PRIVATE
        main.c
        stubs.c
)

target_include_directories(pslab-mini-firmware
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(pslab-mini-firmware
    HAL::STM32::H5::CORTEX
    HAL::STM32::H5::ICACHE
    HAL::STM32::H5::GPIO
    HAL::STM32::H5::RCC
    HAL::STM32::H5::PWR
    HAL::STM32::H5::PWREx
    CMSIS::STM32::H563xx
    STM32::NoSys
    STM32::Nano
)

stm32_add_linker_script(pslab-mini-firmware PRIVATE STM32H563ZITX_FLASH.ld)
stm32_print_size_of_target(pslab-mini-firmware)
stm32_generate_srec_file(pslab-mini-firmware)
