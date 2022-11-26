#include "UART_LCD.h"
#include<lpc214x.h>

int main(void)
{	unsigned char c;
	int i=0;
	char string[16]; 										//char array to store the string recv from UART
	IO1DIR=0XFFFFFFFF; 									//LCd connected to port1 
	pll_init(); 												//initialise the pll
	uart_int(); 												//initilaise the uart0
	lcd_int(); 													//initilaise the lcd
	
	while(1)
	{ i=0; 															//count that holds number of characters recieved
		c=recieve_char(); 								//recv one character
		while(c!=13 && i<14)  						//13 is ascii value for "enter" whenever enter is encountered loop stops 
			{ string[i++]=c;  
				c=recieve_char();
			}
	  string[i]='\0'; 									//make ith element the end of string
		cmd(0x01);  											//clear screen of lcd
		displayString("STRING IS:"); //displayString is method to print whole string 
		cmd(0xC0); 												//got to line 2 of lcd
		isPalindrome(string);
		cmd(0x80); 												//go to line 1
		delay_ms(10);
	}
	return 0;
}
