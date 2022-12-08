#include "functions.h"
#include<stdio.h>

int main(){ 
	IODIR1=0xFFFFFFFF;
	PINSEL1 = 0x01000000;
	ADC_init();
	LCD_init();
	while(1){ 
		cmd(0x01);
		cmd(0x80);
		display_String("Voltage: ");
		print_voltage();
		delay_milliseconds(100);
	}	
 return 0;
}
