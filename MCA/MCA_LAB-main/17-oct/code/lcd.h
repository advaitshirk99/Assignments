#include<lpc214x.h>
#define bit(x) (1<<x)
#define delay for(unsigned int i=0;i<2000;i++);



void lcd_int();
void dat(unsigned char);
void cmd(unsigned char);
int check_palindrome(unsigned char*);
void string(unsigned char *);
void test1();
void test2();
void test3();


