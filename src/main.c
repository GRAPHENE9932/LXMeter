#include "io.h"

#include <stdbool.h>

void delay() {
    for (volatile uint32_t i = 0; i < 100000; i++) {

    }
}

int main(void) {
    enable_port_clock(PORTA);
    set_port_mode(PORTA, 10, MODE_OUTPUT);

    while (true) {
        write_to_port(PORTA, 10, false);
        delay();
        write_to_port(PORTA, 10, true);
        delay();
    }
}
