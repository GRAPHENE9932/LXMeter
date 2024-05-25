#include "io.h"
#include "addresses.h"

// These functions are relevant only for the STM32F042x4 and STM32F042x6 microcontrollers.

static uint32_t get_gpio_base_address(enum Port port) {
    switch (port) {
    case PORTA:
        return GPIOA_BASE;
    case PORTB:
        return GPIOB_BASE;
    case PORTC:
        return GPIOC_BASE;
    case PORTF:
        return GPIOF_BASE;
    default:
        return 0xFFFFFFFF;
    }
}

void enable_port_clock(enum Port port) {
    *((uint32_t*)(RCC_BASE + RCC_AHBENR_OFFSET)) |= 1u << (17 + port);
}

void set_port_mode(enum Port port, uint8_t port_number, enum PortMode port_mode) {
    uint32_t base = get_gpio_base_address(port);
    
    *((uint32_t*)(base + GPIO_MODER_OFFSET)) &= 0xFFFFFFFC << (port_number * 2);
    *((uint32_t*)(base + GPIO_MODER_OFFSET)) |= (uint32_t)port_mode << (port_number * 2);
}

void write_to_port(enum Port port, uint8_t port_number, bool value) {
    uint32_t base = get_gpio_base_address(port);

    *((uint32_t*)(base + GPIO_ODR_OFFSET)) &= 0xFFFFFFFE << port_number;
    *((uint32_t*)(base + GPIO_ODR_OFFSET)) |= (uint32_t)value << port_number;
}

void enable_continuous_adc(void) {
    // Write 1 to CONT of ADC_CFGR1.
    *((uint32_t*)(ADC_BASE + ADC_CFGR1_OFFSET)) |= (1u << 13);

    // Write 1 to CHSEL0 of ADC_CHSELR.
    *((uint32_t*)(ADC_BASE + ADC_CHSELR_OFFSET)) |= (1u << 0);

    // Write 111 to SMP[2:0] of ADC_SMPR.
    *((uint32_t*)(ADC_BASE + ADC_SMPR_OFFSET)) |= 0b111;

    // Write 1 to ADCEN of RCC_APB2ENR.
    *((uint32_t*)(RCC_BASE + RCC_APB2ENR_OFFSET)) |= (1u << 9);

    // Write 1 to HSI14ON of RCC_CR2.
    *((uint32_t*)(RCC_BASE + RCC_CR2_OFFSET)) |= (1u << 0);

    // Clear ADRDY of ADC_ISR.
    *((uint32_t*)(ADC_BASE + ADC_ISR_OFFSET)) |= (1u << 0);
    
    // Write 1 to ADEN of ADC_CR.
    *((uint32_t*)(ADC_BASE + ADC_CR_OFFSET)) |= (1u << 0);

    // Wait until ADRDY of ADC_ISR is 1.
    while ((*((uint32_t*)(ADC_BASE + ADC_ISR_OFFSET)) & (1u << 0)) == 0) {}
}

void start_continuous_adc(void) {
    // Write 1 to ADSTART of ADC_CR.
    *((uint32_t*)(ADC_BASE + ADC_CR_OFFSET)) |= (1u << 2);
}

uint16_t get_adc_data(void) {
    return *((uint32_t*)(ADC_BASE + ADC_DR_OFFSET));
}

