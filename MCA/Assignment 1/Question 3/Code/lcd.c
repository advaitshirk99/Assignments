#include "lcd.h"
#include<lpc214x.h>
#include<stdint.h>

void delay(unsigned int t){

	unsigned int i, j;
	
	for(i=t; i>0; i--){
		for(j=0; j<3000; j++);		
	}
}

void cmd(char command){
	
	IOPIN0 = ((IOPIN0 & 0xFFFF00FF) | (command << 8)); 	//Sending the command through port0's 8 - 15 pins
	IOSET0 = 0x00000040;																//Setting pin P0.6 of lpc2148 to high, so that EN = 1 on LCD
	IOCLR0 = 0x00000030;																//Setting pin P0.4 and P0.5 to low, so that RS = 0, RW = 0 on LCD
	delay(2);
	IOCLR0 = 0x00000040;																//Setting pin P0.6 of lpc2148 to low, so that EN = 0, RW = 0, RS = 0 on LCD
	delay(5);
}

void init(void){

	IODIR0 = 0x0000FFF0;																//Setting pin P0.4 to P0.15 as output
	delay(10);
	cmd(0x38);																					//Initializing the LCD
	cmd(0x0C);																					//Display ON cursor OFF
	cmd(0x06);																					//Auto increment cursor
	cmd(0x01);																					//Display Clear
	cmd(0x80);																					//First line, first position	
}

void display_character(char msg){

		IOPIN0 = ((IOPIN0 & 0xFFFF00FF) | (msg << 8));	
		IOSET0 = 0x00000050;															//Setting pin P0.4 and P0.6 high, so that RS = 1, EN = 1 on LCD
		IOCLR0 = 0x00000020;															//Setting pin P0.5 low, so that RW = 0
		delay(2);
		IOCLR0 = 0x00000040;															//Setting pin P0.6 to low, so that EN = 0, RS and RW stay unchanged on LCD
		delay(5);
}

void display_string(char *msg){

	uint8_t i = 0;
	while(msg[i] != 0){
	
		IOPIN0 = ((IOPIN0 & 0xFFFF00FF) | (msg[i] << 8));	
		IOSET0 = 0x00000050;															//Setting pin P0.4 and P0.6 high, so that RS = 1, EN = 1 on LCD
		IOCLR0 = 0x00000020;															//Setting pin P0.5 low, so that RW = 0
		delay(2);
		IOCLR0 = 0x00000040;															//Setting pin P0.6 to low, so that EN = 0, RS and RW stay unchanged on LCD
		delay(5);
		i++;
	}
}
