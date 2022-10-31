#include<stdio.h>
#include "lcd.h"

int main(void){
	  IO0DIR|=0XFFF;
		IO1DIR = ~(0x00010000); //configure the input port at port 1.16
    lcd_int();
		cmd(0x80);	//Set cursor at the beginning 
		int trigger =0;
		char *str1;
		str1 = "DIWALI";
		
		while(1){
			if(IO1PIN & (0x00010000)){ //condition for open circuit
				cmd(0x01);	//Clear screen of lcd
				trigger = 0;
			}
			else if(trigger ==0){
				string(str1);
				trigger = 1;
			}
				cmd(0x18);	//shift display left
		}
}
