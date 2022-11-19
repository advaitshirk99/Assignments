#include<lpc214x.h>
#include "pll.h"
#include "timer.h"

int main(){

	IODIR0 = 0x0000000F; 							//Setting pins 0.0 to 0.4 as output pins
	init_pll();
	unsigned int i;
	while(1){
		for(i=0; i<4; i++){							
			IOSET0 |= (1<<i);							//Setting pin 0.0-0.3 to high using for loop
			delay_milliseconds(50);				//Delay of 50 milliseconds
			IOCLR0 |= (1<<i);							//Clearing pin 0.0-0.3 to high using for loop
		}
	}
}
