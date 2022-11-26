#include<lpc214x.h>
#include<stdlib.h>
#include "pll.h"
#include "uart.h"
int isArmstrong(int num){
	  int originalNum, remainder, result=0;
		originalNum= num;
    while (originalNum != 0){
			remainder = originalNum % 10;
			result += remainder * remainder * remainder;
      originalNum /= 10;
    }
		if(result == num) return 1;
		else return 0;
}

int main(){
	unsigned char c;
	int i=0, j=0;
	char string[4];
	IODIR1 = 0xFFFFFFFF;
	init_pll();
	init_uart0();
	char str1[] = "NOT ARMSTRONG";
	char str2[] = "ARMSTRONG";
	while(1){
		i=0;
		c = receive_char_uart0();
		while(c != 13 && i<4){
			string[i++] = c;
			c = receive_char_uart0();
		}
		string[i] ='\0';
		int num;
		num= atoi(string);
		
		if(isArmstrong(num) == 1){
			while(str2[j] != '\0'){
				transmit_char_uart0(str2[j++]);
			}
			j=0;
		}
		else if(isArmstrong(num) == 0){
			while(str1[j] != '\0'){
				transmit_char_uart0(str1[j++]);
			}
			j=0;
		}
	}
}
