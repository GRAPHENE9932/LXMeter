#include "io.h"

#include <stdbool.h>

void delay() {
    for (volatile uint32_t i = 0; i < 100000; i++) {

    }
}

int main(void) {
    enable_port_clock(PORTA);
    set_port_mode(PORTA, 0, MODE_ANALOG);
    set_port_mode(PORTA, 10, MODE_OUTPUT);

    enable_continuous_adc();
    start_continuous_adc();

    while (true) {
        uint16_t num_shifted = get_adc_data();
        for (uint8_t i = 0; i < 16; i++) {
            num_shifted >>= 1;
            write_to_port(PORTA, 10, num_shifted & 1u);
            delay();
        }
    }
}
