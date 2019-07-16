#include <avr/io.h>

void delay_timer0(){
	
	TCNT1 = 3037; //load timer counter register with 0
	
	TCCR1A = 0x00; //Set the Timer1 under normal mode with 1:8 prescaler
	TCCR1B = 0x04;
	
	while((TIFR1 & 0x01)==0); /*wait till the timer overflow bit (T0V0) is set*/
	
	TCCR1A = 0x00; //clear settings (Stops timer)
	TCCR1B = 0x00;
	
	TIFR1 = 0x01; /*Set T0V0 =1 clear the timer*/

}

int main(void){
	
	DDRB =0xFF; //make pin 5 of portB output
	
	sei();
    

while(1){
	
	for(int i=4;i>=2;i--){
      PORTB = PORTB | (1<<i);
      _delay_ms(200);
      PORTB = PORTB &~(1<<i);

    }
     for(int j=2;j<=3;j++){
      PORTB = PORTB | (1<<j);
      _delay_ms(200);
      PORTB = PORTB &~(1<<j);

    }
	
	
	
}	
	
}

ISR (TIMER1_OVF_vect) {
//your program
    PORTB =PORTB ^ (1<<5);//toggle pin 5
	delay_timer0();
}
