#include<lpc214x.h>

int main(){
	PINSEL0 = 0x00000000;									//defining port0's 0-15 pins as GPIO
	IODIR0	= 0xFFFF;											//Setting port0's 0-15 pins as output pins
	PINSEL2 = 0x00000000;									//Defining port1's 16-31 pins as GPIO
	IODIR1 	= 0xFFF0FFFF;									//Setting port1's 16-19 pins as input
	
	while(1){
		if(IOPIN1 & 0x00010000){
			IOCLR0 = 0xF;											//Setting port0's 0-3 pins as low
		}
		else{
			IOSET0 = 0xF;											//Setting port0's pins 0-3 high
		}
	}
}
