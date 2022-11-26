#include"lcd.h"
void lcd_int()
{
    cmd(0x38);
    cmd(0x0c);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);
}

void cmd(unsigned char a)
{
    IO0PIN&=0x00;
    IO0PIN|=(a<<0);
    IO0CLR|=bit(8);                //rs=0
    IO0CLR|=bit(9);                //rw=0
    IO0SET|=bit(10);               //en=1
    delay;
    IO0CLR|=bit(10);               //en=0
}

void dat(unsigned char b)
{
    IO0PIN&=0x00;
    IO0PIN|=(b<<0);
    IO0SET|=bit(8);                //rs=1
    IO0CLR|=bit(9);                //rw=0
    IO0SET|=bit(10);               //en=1
    delay;
    IO0CLR|=bit(10);               //en=0
}

int check_palindrome(unsigned char* str){
unsigned int i=0;
unsigned char *temp;
temp=str;	
	while(*str!='\0') 
	 { i++;
		 str++;
	 }
	 for(int j=0;j<i/2;j++)
	 { if(*(temp+j)!=*(temp+i-j-1)) return 0;
		 
	 } 
	 return 1;
}


void string(unsigned char *p)
{
    while(*p!='\0') {
        dat(*p++);
    }
}

void test1()
{
		IO0DIR|=0XFFF;
    lcd_int();
    cmd(0x80);
		char str[]="mom"; //change string value to test .
		int c=check_palindrome(str);
    if(c) string("Is a palindrome");
		else string("Not palindrome");
}

void test2()
{ 	
	  IO0DIR|=0XFFF;
		IO1DIR|=0X0;
    lcd_int();
    cmd(0x80);
		string("DIWALI!!");
		while(1){
		if((IO1PIN & bit(16))==0)
		{cmd(0X18);
		 while((IO1PIN & bit(16))==0);	 
		 //wait for switch to change state
		}			
		}
}	

void test3()
{ IO0DIR|=0XFFF;
	IO1DIR|=0X0;
	lcd_int();
	short unsigned int count=0;
	string("Count:");
	while(1){
		if((IO1PIN & bit(16))==0 && count <10)
		{ cmd(0Xc0);
			count++;
			dat(47+count);
		 while((IO1PIN & bit(16))==0);	
			
		 //wait for switch to change state
		}			
		if((IO1PIN & bit(17))==0 && count>0)
		{ cmd(0Xc0);
			count--;
			dat(47+count);
		 while((IO1PIN & bit(17))==0);	}
		}	
	}