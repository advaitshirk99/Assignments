#include<lpc214x.h>
#include "functions.h"

int main(){
	PINSEL0 |= 0x0;
	IODIR0 |= 0xEF;
	unsigned int a=0;
	while(1){
		if((IO0PIN & bit(4))==0){
		 while((IO0PIN & bit(4))==0);
		}
		if(a==0) 
		{	IOSET0|=bit(1);
			a=1;
		}	
		else
		{ IO0CLR|=bit(1);
			a=0;
		}
	}
}
