#include "timer.h"
#include<lpc214x.h>

void delay_milliseconds(unsigned int ms){
	T0CTCR = 0x00;
	T0TCR = 0x00;				//Enable timer mode
	T0PR = 59999;				//For 1ms
	T0TCR = 0x02;				//Reset timer
	T0TC = 0;
	T0TCR = 0x01;				//Enable timer
	while(T0TC < ms);
	T0TCR = 0x00;				//Disable timer
	T0TC = 0;						//Clear the timer
}
	
void delay_microseconds(unsigned int us){
	T0CTCR = 0x00;
	T0TCR = 0x00;				//Enable timer mode
	T0PR = 59;					//For 1us
	T0TCR = 0x02;
	T0TCR = 0x01;				//Enable timer
	while(T0TC < us);
	T0TCR = 0x00;				//Disable timer
	T0TC = 0;						//Clear the timer
}
