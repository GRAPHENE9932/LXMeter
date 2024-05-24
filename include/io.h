#ifndef IO_H
#define IO_H

#include <stdint.h>
#include <stdbool.h>

enum Port : uint8_t {
    PORTA = 0,
    PORTB = 1,
    PORTC = 2,
    PORTD = 3,
    PORTE = 4,
    PORTF = 5
};

enum PortMode : uint8_t {
    MODE_INPUT = 0b00,
    MODE_OUTPUT = 0b01,
    MODE_ALTERNATE = 0b10,
    MODE_ANALOG = 0b11
};

void enable_port_clock(enum Port port);
void set_port_mode(enum Port port, uint8_t port_number, enum PortMode port_mode);
void write_to_port(enum Port port, uint8_t port_number, bool value);

#endif // IO_H
