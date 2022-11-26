#include<lpc214x.h>
int main()
{
    
  IO0DIR|= 0x0F;  									//Configure P0.0-P0-3 as Output and P0.4-P0.7 as Input
  while(1){
		if((IO0PIN & (1<<4)) ==0)  			//Check if the switch connected to P0.4 is pressed
			IO0SET |=0xFF;                  
		else
			IO0CLR |=0xFF; 	       
  }
}
