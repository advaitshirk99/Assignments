#include<lpc214x.h>
#include "timer.h"
#include "pll.h"
#define bit(x) 1<<x

int main(){
	init_pll();
	PINSEL0 = 0x00000000;									//Defining Port0's 0 to 15 pins as GPIO pins
	IODIR0 = 0xFF;										//Defining Port0's 0 to 7 pins as output pins
	unsigned int i;
	
	while(1){
		for(i=0; i<8; i++){	
			IOSET0 = bit(i);						//Setting pin i high
			delay_milliseconds(50);			//Delay for 50ms
			IOCLR0 = bit(i);						//Setting pin i low
		}
	}
}
