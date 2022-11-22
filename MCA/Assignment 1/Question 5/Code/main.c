#include<lpc214x.h>
#include "LED_7segment.h"

int main(){
	PINSEL0 = 0x00000000;
	PINSEL1 = 0x00000000;
	IODIR0 	= 0xFFFFFFFF;
	
	while(1){
		while(1){
			IOSET0 |= 0x1AA1B6CF;								//The hex representation of MSIS for 7 segment LED
		}
	}
}
