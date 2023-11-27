#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef _BV
    #define _BV(bit) (1<<(bit))
#endif

volatile uint8_t x = 5;

int main(void) {
    DDRB |= _BV(PB0);
    DDRD &= ~(_BV(PD0) | _BV(PD1));

    PORTD = 0b00000011;
    PORTB = 0;

    sei();

    TIMSK |= _BV(TOIE0);
    TCCR0 |= _BV(CS00);

    while (1) {
        if(!(PIND & _BV(PD0))) {
            if(x < 100) x += 5;
        }
        if(!(PIND & _BV(PD1))) {
            if (x > 5) x -= 5;
        }
        _delay_ms(100);
    }
}

ISR(TIMER0_OVF_vect) {
    static uint8_t i = 0; i++;
    if(i == x) {
        PORTB &= ~(_BV(PB0));
    }
    if(i == 100) {
        PORTB |= (_BV(PB0)); i=0;
    }
}