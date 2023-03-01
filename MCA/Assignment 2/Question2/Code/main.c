#include<lpc214x.h>
#include "timer.h"
#include "pll.h"
#define bit(x) 1<<x

int main(){ 
	init_pll();
	IODIR0 = 0x4;
	while(1){ 
		if((IO0PIN & (1<<0)) == 0){ 
			IOSET0 |= (1<<2);
			delay_milliseconds(1000);
			IOCLR0 |= (1<<2);
			delay_milliseconds(1000);
		}
		else{ 
			IOSET0 |= (1<<2);
			delay_milliseconds(500);
			IOCLR0 |= (1<<2);
			delay_milliseconds(500);
		}
	}
 return 0;
}
