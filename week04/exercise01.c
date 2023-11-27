#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef _BV
    #define _BV(bit) (1<<(bit))
#endif

#define LED1 _BV(PB0)

int main(void) {
    DDRB |= LED1;
    PORTB |= LED1;

    sei();

    TIMSK |= _BV(TOIE0);
    TCCR0 |= (1 << CS00) | (1 << CS01);
    TCNT0 = 12;

    while (1) {}
}

ISR(TIMER0_OVF_vect) {
    static uint8_t i = 0;
    i++;

    if (i == 64) {
        PORTB ^= LED1;
        i = 0;
    }
}