#include "header.h"
#include<stdio.h>
#include<stdlib.h>

void store_string(FILE* ptr){
	
	printf("Press ENTER to stop\n");

	char sentence[MAX_STRING_LENGTH];
	
	//fgets stores the first string from the stream (in this case - stdin) to the character array 'sentence' 
	fgets(sentence, MAX_STRING_LENGTH, stdin);
	int i=0;
	
	//The while condition only fails when 0x0A (ASCI value for 'ENTER') is deteced in the character array
	while(sentence[i] != 0x0A){
		
		//Inserts the characters in the destination file character by character
		fputc(sentence[i], ptr);
		i++;
	}	
}

