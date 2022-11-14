#include<lpc21xx.h>
#include "lcd_header.h"

int main()
{
    IO0DIR|=0XFFF;                 // Port 0 (P0.0 - P0.11) is configured as OUTPUT
    init();                    // Call initialization function for LCD initialization
    isPalindrome("malayalam");     //Call palindrome function and check if the given word is palindrome or not
    while(1) 
		{
        delay(100);                   //Call Delay Function
    }
}
