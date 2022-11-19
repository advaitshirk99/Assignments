#include<lpc214x.h>
#include "lcd_header.h"

int main(){
	PINSEL0 |= 0x003;											//Setting Pins 0.0 and 0.1 as RxD and TxD, and remaining pins as GPIO pins
	IODIR0 |= 0xFFD;											//Pins 0.0 - 0.11 as output pins, and 0.1 as input pin
	
}
	