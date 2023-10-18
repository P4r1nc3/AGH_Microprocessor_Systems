#include <avr/io.h>


int main(void)
{
    DDRB |= (1<<PB0);
    while (1)
    {
        PORTB &= ~ (1<<PB0);
    }
    return 0;
}

