#include<lpc214x.h>
#include "lcd_header.h"
#include "pll.h"
#include "uart.h"
#include "timer.h"

int main(){
	IODIR0 = 0x0;
	IODIR1 = 0xFFFFFFFF;									//port1 as output
	char a;
	char str[20];
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
	return 0;
}

