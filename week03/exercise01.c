#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef _BV
    #define _BV(bit) (1<<(bit))
#endif

#define LED1 _BV(PB0)
#define LED2 _BV(PB1)

int main(void)
{
    DDRB |= LED1 | LED2;
    PORTB |= LED1 | LED2;

    sei();

    TIMSK |= _BV(TOIE0);
    TCCR0 |= _BV(CS02) | _BV(CS00);

    while (1){}
    return 0;
}

ISR(TIMER0_OVF_vect)
{
    static uint8_t i = 0, j = 0;
    i++;
    j++;

    if(i == 4) {
        PORTB ^= ~LED1;
        i = 0;
    }

    if(j == 8) {
        PORTB ^= ~LED2;
        j = 0;
    }
}
