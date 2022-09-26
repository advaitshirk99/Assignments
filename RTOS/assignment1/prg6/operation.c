#include "header.h"
#include<stdlib.h>

void copy_text(FILE* source, FILE* destination){

	int i;
	char c = fgetc(source);

	while(c != EOF){
	
		fputc(c, destination);
		c = fgetc(source);
	}	
}
