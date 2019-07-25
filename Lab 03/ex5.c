#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define BLINK_DELAY_MS

/*void delay_timer0(){
	
	TCNT1 = 3037; //load timer counter register with 0
	
	TCCR1A = 0x00; //Set the Timer1 under normal mode with 1:8 prescaler
	TCCR1B = 0x04;
	
	while((TIFR1 & 0x01)==0); /*wait till the timer overflow bit (T0V0) is set*/
	
	/*TCCR1A = 0x00; //clear settings (Stops timer)
	TCCR1B = 0x00;
	
	TIFR1 = 0x01; /*Set T0V0 =1 clear the timer*/

//}*/


//interrrupt routine
ISR (TIMER1_OVF_vect) {
//your program
    PORTB = PORTB ^(1<<5);//toggle pin 5
	
	
}


int main(void){
	int i,j = 0;
	
	
	DDRB =0xFF; //make pin 5 of portB output
	TIMSK1 =(1<<TOIE1);//enabling timw overflow interrupt
	TCNT1 = 3037; //load timer counter register with 3037
	
	
	TCCR1A = 0x00; //Set the Timer1 under normal mode with 1:8 prescaler
	TCCR1B = 0x04;
	
	
	sei();
	
    

while(1){
	
	for(i=4;i>=1;i--){
      PORTB = PORTB | (1<<i);
      _delay_ms(200);
      PORTB = PORTB &~(1<<i);

    }
     for(j=2;j<=3;j++){
      PORTB = PORTB | (1<<j);
      _delay_ms(200);
      PORTB = PORTB &~(1<<j);

    }
	
	
	
}	
	
}
