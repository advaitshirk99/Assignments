#include "header.h"

int char_count(char str[]){

	int i=0, count=0;
	for (i=0; str[i] != '\0'; i++){
		
		if(str[i] != ' ') count++;
	}

	return count;
}
