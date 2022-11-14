#include<stdio.h>
#include<stdlib.h>
#include<lpc21xx.h>

void delay_ms(int j) //Function for delay in milliseconds
{
    int x,i;
    for(i=0;i<j;i++)
    {
        for(x=0; x<6000; x++);    // loop to generate 1 millisecond delay with Cclk = 60MHz
    }
}

void LCD_CMD(char command)
{
    IO0PIN = ( (IO0PIN & 0xFFFF00FF) | (command << 8));
    IO0SET = 0x00000040; //EN = 1
    IO0CLR = 0x00000030; //RS = RW = 0
    delay_ms(2);
    IO0CLR = 0x00000040; //EN = 0
    delay_ms(5);
}

void LCD_INIT(void)
{
    IO0DIR = 0x0000FFF0; /* P0.8 to P0.15 LCD Data. P0.4,5,6 as RS RW and EN */
    IO1DIR = 0x0;
    delay_ms(20);
    LCD_CMD(0x38);  /* Initialize LCDcommand */
    LCD_CMD(0x0C);   /* Display on cursor off */
    LCD_CMD(0x06);  /* Auto increment cursor */
    LCD_CMD(0x01);   /* Display clear */
    LCD_CMD(0x80);  /* First line first position */
}

void LCD_CHAR(char msg)
{
    IO0PIN = ( (IO0PIN & 0xFFFF00FF) | (msg << 8));
    IO0SET = 0x00000050; //RS = 1, EN = 1
    IO0CLR = 0x00000020; //RW = 0
    delay_ms(2);
    IO0CLR = 0x00000040;
    delay_ms(5);
}

void LCD_STRING (char* msg)
{
    int i=0;
    while(msg[i]!=0)
    {
        LCD_CHAR(msg[i]);
        i++;
    }
}
