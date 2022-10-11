#include "header.h"

//Function to count the number of characters in the given string (excluding space)
int char_count(char str[]){

	int i=0, count=0;
	for (i=0; str[i] != '\0'; i++){
		
		if(str[i] != ' ') count++;
	}

	return count;
}
