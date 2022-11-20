#include<lpc214x.h>
#include "lcd_header.h"
#include "pll.h"
#include "uart.h"
#include "timer.h"

int main(){
	PINSEL0 |= 0x004;											//Setting Pins 0.0 and 0.1 as RxD and TxD, and remaining pins as GPIO pins
	IODIR0 |= 0xFFD;											//Pins 0.0 - 0.11 as output pins, and 0.1 as input pin
	char a;
	char str[100];
	unsigned int i=0;
	init_pll();
	init_uart0();
	lcd_init();
	
	while(1){
	
		a = receive_char_uart0();
		while(a != 13 && i<14){
			str[i++] = a;
			a = receive_char_uart0();
		}
		str[i] = '\0';
		cmd(0x01);
		display_string("String received:");
		cmd(0xC0);
		display_string(&str[0]);
		cmd(0x80);
		delay_milliseconds(20);
	}
}

