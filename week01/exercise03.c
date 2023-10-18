#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1<<PB0);
    DDRB |= (1<<PB1);
    while (1)
    {
        PORTB |= (1<<PB0);
        PORTB &= ~(1<<PB1);
        _delay_ms(1000);
        PORTB ^= (1<<PB0);
        PORTB ^= (1<<PB1);
        _delay_ms(1000);
    }

    return 0;
}

