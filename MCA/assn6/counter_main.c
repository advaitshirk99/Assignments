#include "lcd_counter.h"
#include<lpc21xx.h>
#include<stdio.h>

int main()
{
    int j;
    j = 0;
    char val_j[8];
    LCD_INIT();
    LCD_STRING("COUNTER: ");
    while(1)
    {
        if((IO1PIN & (1<<16)) == 0)
        {
            j = j + 1;
            sprintf(val_j, "%d", j);
            LCD_STRING(val_j);
            LCD_CMD(0xCC);
        }
        else if((IO1PIN & (1<<17)) == 0)
        {
            j = j - 1;
            sprintf(val_j, "%d", j);
            LCD_STRING(val_j);
            LCD_CMD(0xCC);
        }
    }
    return 0;
}
