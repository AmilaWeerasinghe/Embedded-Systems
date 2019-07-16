#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS


int main (void){
    DDRB =0xFF;
    /* configure PORTB for output*/
	int i=0;
while(1){
    for(i=5;i>=2;i--){
      PORTB = PORTB | (1<<i);
      _delay_ms(200);
      PORTB = PORTB &~(1<<i);

    }
     for(i=3;i<=4;i++){
      PORTB = PORTB | (1<<i);
      _delay_ms(200);
      PORTB = PORTB &~(1<<i);

    }
    

}
}