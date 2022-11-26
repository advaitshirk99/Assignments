#include<lpc214x.h>
#define bit(x) (1<<x)

void pll_init(void){
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

void uart_int(void){
  PINSEL0=0X5;
  U0LCR=0X83;            
  U0DLL=135;
  U0DLM=1;
  U0LCR=0X03;          
}

void delay_ms(unsigned int ms){
	T0CTCR=0x0;                                 
	T0TCR=0x00;                
	T0PR=59999;                 
	T0TCR=0x01;                
	while(T0TC<ms);           
	T0TCR=0x00;                 
	T0TC=0;   
}

void cmd(unsigned char a){
	IO1PIN&=0x00;
	IO1PIN=(a<<16);
	IO1CLR|=bit(25);               
	IO1CLR|=bit(26);               
	IO1SET|=bit(27);               
	delay_ms(2);
	IO1CLR|=bit(27);               
}

void dat(unsigned char b){
	IO1PIN&=0x00;
	IO1PIN=(b<<16);
	IO1SET|=bit(25);               
	IO1CLR|=bit(26);               
	IO1SET|=bit(27);              
	delay_ms(2);
	IO1CLR|=bit(27);               
}


void lcd_int(void){
	cmd(0x38);
	cmd(0x0c);
	cmd(0x06);
	cmd(0x01);
	cmd(0x80);
}

void displayString(char* s){ 
	while(*s!='\0'){ 
		dat(*s++);
	}
}	

char recieve_char(void){	
  unsigned char a;
  while((U0LSR&(1<<0))==0);         //Checking RDR bit
  a=U0RBR;
  return a;
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
		  displayString(word);                //Display the word on the LCD
	    cmd(0xC0);                 					//Force cursor to the second line
		  displayString("PALINDROME");        //Display "PALINDROME" on LCD 
		}
    else                           				 //if the word is not a palindrome
		{
		  displayString(word);              	 //Display the word on the LCD
	    cmd(0xC0);                					//Force cursor to the second line
		  displayString("NOT PALINDROME");  //Display "NOT A PALINDROME" on LCD 
		}
}
