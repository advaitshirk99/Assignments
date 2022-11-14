#include<stdio.h>
#include<lpc214x.h>
#include "lcd_header.h"

int main(void){
	  IO0DIR|=0XFFF;								//P0.0 - P0.11 set as output pins
    init();
		cmd(0x80);										//Set cursor at the beginning 
		char *str1;
		str1 = "DIWALI ";
		display_string(str1);
		
	while(1){
		if((IOPIN1 & (1<<16)) == 0){
			cmd(0x18);									//LCD command for shifting the display to the left
			delay(2);
			cmd(0x8F);
			display_string(str1);
			cmd(0x18);
		}
	}
}
