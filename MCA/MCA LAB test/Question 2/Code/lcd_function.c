#include "lcd_header.h"
#include<lpc214x.h>
#include<stdint.h>

void delay(unsigned int t){

	unsigned int i, j;
	
	for(i=t; i>0; i--){
		for(j=0; j<3000; j++);		
	}
}

void cmd(unsigned char command){
	
	IO1PIN&=0x00;																			 	//Sending the command through port0's 8 - 15 pins
	IO1PIN=(command<<16);																//Setting pin P0.6 of lpc2148 to high, so that EN = 1 on LCD
	IO1CLR|=bit(25);																		//Setting pin P0.4 and P0.5 to low, so that RS = 0, RW = 0 on LCD
	IO1CLR|=bit(26);
	IO1SET|=bit(27);
	delay(2);
	IO1CLR|=bit(27);																		//Setting pin P0.6 of lpc2148 to low, so that EN = 0, RW = 0, RS = 0 on LCD
}

void lcd_init(void){

	IODIR0 = 0x0000FFF0;																//Setting pin P0.4 to P0.15 as output
	//delay(10);
	cmd(0x38);																					//Initializing the LCD
	cmd(0x0C);																					//Display ON cursor OFF
	cmd(0x06);																					//Auto increment cursor
	cmd(0x01);																					//Display Clear
	cmd(0x80);																					//First line, first position	
}

void display_character(char msg){

    IO1PIN&=0x00;
    IO1PIN=(msg<<16);
    IO1SET|=bit(25);               
    IO1CLR|=bit(26);               
    IO1SET|=bit(27);              
    delay(2);
    IO1CLR|=bit(27);  
}

void display_string(char *msg){

	 while(*msg!='\0'){
		 display_character(*msg++);
	}
}

void isPalindrome(char* word){
    char *ptr, *rev;
    ptr = word;
    while (*ptr != '\0'){
        ++ptr;
    }
    --ptr;
 
    for (rev = word; ptr >= rev;){
        if (*ptr == *rev){
            --ptr;
            rev++;
        }
        else
            break;
       }
		
    if (rev > ptr){
		  display_string(word);                 //Display the word on the LCD
	    cmd(0xC0);                 //Force cursor to the second line
		  display_string("PALINDROME");         //Display "PALINDROME" on LCD 
		}
    else                            //if the word is not a palindrome
		{
		  display_string(word);                //Display the word on the LCD
	    cmd(0xC0);                //Force cursor to the second line
		  display_string("NOT A PALINDROME");  //Display "NOT A PALINDROME" on LCD 
		}
}
