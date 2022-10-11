#include "header.h"
#include<stdlib.h>

//Function to copy text, character by character to the destination file
void copy_text(FILE* source, FILE* destination){

	int i;
	char c = fgetc(source);

	while(c != EOF){
	
		fputc(c, destination);
		c = fgetc(source);
	}	
}
