#include<lpc214x.h>
#include "timer.h"
#include "pll.h"
#define bit(x) 1<<x

int main(){
	init_pll();
	PINSEL0 = 0x0;
	PINSEL1 = 0x0;
	PINSEL2 = 0x0;
	IODIR0 = 0xFFFFF;
	IODIR1 = 0x0;
	while(1){
		if((IOPIN1 & (1<<16)) == 0){
			IOSET0 |= 0xFFFFF;
			delay_milliseconds(100);
			IOCLR0 |= 0xFFFFF;
		}
		else{
			IOSET0 |= 0xFFFFF;
			delay_milliseconds(50);
			IOCLR0 |= 0xFFFFF;			
		}
	}
}
