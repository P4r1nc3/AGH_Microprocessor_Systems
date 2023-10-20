#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#ifndef _BV
    #define _BV(bit) (1<<(bit))
#endif

int main(void)
{
    DDRB |= _BV(PB0)| _BV(PB1)| _BV(PB2);
    DDRC &= ~_BV(PC0);
    PORTC |= _BV(PC0);

    while (1)
    {
        if (!(PINC & _BV(PC0)))
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
        else
        {
            PORTB |= _BV(PB0)| _BV(PB1)| _BV(PB2);
        }
    }
    return 0;
}
