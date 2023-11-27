#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef _BV
    #define _BV(bit) (1<<(bit))
#endif

#define LED1 _BV(PB0)
#define LED2 _BV(PB1)
#define LED3 _BV(PB2)
#define LED4 _BV(PB3)

int main(void) {
    DDRB |= LED1 | LED2 | LED3 | LED4;
    PORTB |= LED1 | LED2 | LED3 | LED4;

    DDRD = 0;
    PORTD |= (_BV(PD4) | _BV(PD0));

    TCCR0 |= (_BV(CS01) | _BV(CS02));
    TCCR0 &= ~(_BV(CS00));

    while (1) {
        PORTB = ~TCNT0;

        if(TCNT0 >= 0b00010000) {
            TCNT0=0;
        }

        if(!(PIND &= (_BV(PD0)))) {
            TCNT0=0;
        }
    }
    return 0;
}