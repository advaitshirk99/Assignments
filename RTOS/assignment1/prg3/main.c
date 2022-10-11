#include "header.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	
	int i;
	char string[MAX_STRING_LENGTH];	//Character array to store the contents of the file character by character
	FILE* fptr = fopen(argv[1], "r");
	if (fptr == NULL){
		printf("No such file.\n");
		return 0;
	}
	
	//Storing the contents of the file character by character, till end of file (feof) is received.
	for(i=0; !feof(fptr); i++) fscanf(fptr, "%c", &string[i]);
	
	printf("String from the file: \n%s", string);
	printf("\nThe number of characters in the string: %d\n", char_count(string));

	return 0;

}
