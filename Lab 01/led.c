#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS
int main (void){
DDRB = DDRB|(1<<5); /* configure pin 5 of PORTB for output*/
DDRB = DDRB|(1<<4);
DDRB = DDRB|(1<<3);
DDRB = DDRB|(1<<2);
while(1){
 
 for(int i=5;i>=2;i--){
	 PORTB = PORTB | (1<<i); /* set pin 5 high to turn led on */
 _delay_ms(100);
 PORTB = PORTB &~(1<<i); /* set pin 5 low to turn led off */
 _delay_ms(100);
	 
 }
 for(j=3;j<=4){
	 PORTB = PORTB | (1<<j); /* set pin 5 high to turn led on */
 _delay_ms(100);
 PORTB = PORTB &~(1<<j); /* set pin 5 low to turn led off */
 _delay_ms(100);
	 
 }
}
}