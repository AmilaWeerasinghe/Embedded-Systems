#include <avr/io.h>

void delay_timer0(){
	
	TCNT0 = 131; //load timer counter register with 0
	
	TCCR0A = 0x00; //Set the Timer0 under normal mode with 1:8 prescaler
	TCCR0B = 0x04;
	
	while((TIFR0 & 0x01)==0); /*wait till the timer overflow bit (T0V0) is set*/
	
	TCCR0A = 0x00; //clear settings (Stops timer)
	TCCR0B = 0x00;
	
	TIFR0 = 0x01; /*Set T0V0 =1 clear the timer*/

}

int main(void){
	
	DDRB = DDRB | (1<<5); //make pin 5 of portB output
    

while(1){
	PORTB =PORTB ^ (1<<5);//toggle pin 5
	delay_timer0();
	
	
}	
	
}