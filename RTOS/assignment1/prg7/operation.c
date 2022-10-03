#include "header.h"
#include<stdio.h>
#include<stdlib.h>

void store_string(FILE* ptr){
	
	printf("Press ENTER to stop\n");

	char sentence[MAX_STRING_LENGTH];
	
	fgets(sentence, MAX_STRING_LENGTH, stdin);
	int i=0;
	//char c = getchar()
	while(sentence[i] != 0x0A){
	
		fputc(sentence[i], ptr);
		i++;
	}	
}

