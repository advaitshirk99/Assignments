#include<lpc214x.h>
#include "lcd.h"
#define bit(x) 1<<x

int main(){
	PINSEL0 = 0x00000000;										//Port0's pins 0-15 as GPIO 
	IODIR0 	=	0xFFFF;												//Port0's pins 0-15	as output
	PINSEL2 = 0x00000000;										//Port1's pins 0-15 as GPIO
	IODIR1 	= 0x00000000;										//Port1's pins 16-19 as output
	init();
	cmd(0x80);
	
	while(1){
		if(IOPIN1 & 0x00010000){
			display_string("MSIS");
			cmd(0x80);
		}
		else{
			cmd(0x01);													//Clear the lcd
			delay(20);
			display_string("MSIS");
		}
	}
}
