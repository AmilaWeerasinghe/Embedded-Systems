#include <avr/io.h>


int main(void)
{
    DDRD |= (1 << DDD6);
    // PD6 is now an output

    OCR0A = 40;
    // set PWM for 50% duty cycle


    TCCR0A |= (1 << COM0A1);
    // set none-inverting mode

    TCCR0A |= (1 << WGM01) | (1 << WGM00);
    // set fast PWM Mode

    TCCR0B |= (1 << CS00)|(1<<CS10);
    // set prescaler to 64 and starts PWM


    while (1);
    {
        // we have a working Fast PWM
		
		
    }
}
