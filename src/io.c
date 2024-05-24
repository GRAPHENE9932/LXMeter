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
