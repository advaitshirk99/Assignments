#include<lpc214x.h>
#include "LED_7segment.h"

unsigned int arr[] = {0xf3, 0x12, 0x163, 0x133, 0x192, 0x1b1, 0x1f1, 0x13, 0x1f3, 0x1b3};	//Value to activate individual LED of the 7 segment display on port0, pins 0 - 8
unsigned int arr1[] = {0x00f30000, 0x00120000, 0x1630000, 0x1330000, 0x1920000, 0x1b10000, 0x1f10000, 0x130000, 0x1f30000, 0x1b30000};	//Value to activate individual LED of the 7 segment display on port1, pins 16 - 31

int main(){
	PINSEL0 = 0x00000000;				//Defining port0's pins as GPIO pins
	IODIR0 = 0x0000FFFF;				//Setting pins 0 to 8 of port0 as output
	PINSEL2 = 0x00000000;				//Defining port1's pins as GPIO pins
	IODIR1 = 0xFFFF0000;				//Setting pins 0 to 8 of port1 as output
	int i, j=9;
	
	while(1){
		IOSET1 |= arr1[j];
		for(i=9; i>=0; i--){
				IOSET0 |= arr[i];				//Setting the pins high for the corresponding digit
				delay(15);							
				IOCLR0 |= arr[i];				//Setting pins low for the corresponding digit
				delay(2);
			}													
		IOCLR1 |= arr1[j];					//Setting pins low for the corresponding digit
		j--;		
	}
	return 0;
}
