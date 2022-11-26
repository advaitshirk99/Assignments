#include<lpc214x.h>
#define bit(x) (1<<x)

void pll_init(void)                  
{
    PLL0CON=0x01;
    PLL0CFG=0x24;
    PLL0FEED=0xaa;
    PLL0FEED=0x55;
    while(!(PLL0STAT&(1<<10)));
    PLL0CON=0x03;
    PLL0FEED=0xaa;
    PLL0FEED=0x55;
    VPBDIV=0x01;
}

void delay_ms(unsigned int ms)
{
    T0CTCR=0x0;                                 
    T0TCR=0x00;                
    T0PR=59999;                 
    T0TCR=0x01;                
    while(T0TC<ms);           
    T0TCR=0x00;                 
    T0TC=0;   
}

void cmd(unsigned char a)
{
    IO0PIN&=0x00;
    IO0PIN=(a<<3);
    IO0CLR|=bit(0);               
    IO0CLR|=bit(1);               
    IO0SET|=bit(2);               
    delay_ms(2);
    IO0CLR|=bit(2);               
}

void dat(unsigned char b)
{
    IO0PIN&=0x00;
    IO0PIN=(b<<3);
    IO0SET|=bit(0);               
    IO0CLR|=bit(1);               
    IO0SET|=bit(2);              
    delay_ms(2);
    IO0CLR|=bit(2);               
}


void lcd_int(void)
{
    cmd(0x38);
    cmd(0x0c);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);
}

void displayString(char* s)
{ while(*s!='\0')
	{ dat(*s++);
	}
}	

