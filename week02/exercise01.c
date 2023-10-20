#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#ifndef _BV
    #define _BV(bit) (1<<(bit))
#endif

int main(void)
{
    DDRB |= _BV(PB0)| _BV(PB1)| _BV(PB2);
    while (1)
    {
        PORTB |= _BV(PB0) | _BV(PB1);
        PORTB &= ~_BV(PB2);
        _delay_ms(500);

        PORTB |= _BV(PB0) | _BV(PB2);
        PORTB &= ~_BV(PB1);
        _delay_ms(500);

        PORTB |= _BV(PB1) | _BV(PB2);
        PORTB &= ~_BV(PB0);
        _delay_ms(500);
    }
    return 0;
}
