#include"header.h"

int main(void)
{ IODIR0=0XFFFFFFFF; 
	IO1DIR=0x00000000;
	lcd_int();
	displayString("MSIS");
	while(1)
	{ if((IO1PIN & bit(16))==0)
		{
		 while((IO1PIN & bit(16))==0);
		 while((IO1PIN & bit(16))!=0)
		 { cmd(0x08);
			 delay_ms(25);
			 cmd(0x0C);
			 delay_ms(25);
		 }
		 while((IO1PIN & bit(16))==0);
		}
	}
	return 0;
}