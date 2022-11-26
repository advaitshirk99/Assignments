#include<lpc214x.h>
#include "timer.h"
#include "pll.h"
#include<stdint.h>

int main(){
	init_pll();
	uint8_t i;
	i = 0;
	uint16_t value;
	PINSEL1 = 0x00080000;										//P0.25 as DAC output
	IO0DIR = ( IO0DIR & 0xFFFFF0FF ); 			//Input pins for switch. P0.8 sine
	uint16_t sin_wave[42] = {512,591,665,742,808,873,926,968,998,1017,1023,1017,998,968,926,873,808,742,665,591,512,
													436,359,282,216,211,151,97,55,25,6,0,6,25,55,97,151,211,216,282,359,436 };
	while(1){
		if(!(IO0PIN & (1<<8))){
			while(i !=42)
				{
					value = sin_wave[i];
					DACR = ( (1<<16) | (value<<6) );
					delay_milliseconds(1);
					i++;
				}
			i = 0;
		}
	}
}
