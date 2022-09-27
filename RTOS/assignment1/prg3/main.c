#include "header.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	
	int i;
	char string[MAX_STRING_LENGTH];
	FILE* fptr = fopen(argv[1], "r");
	if (fptr == NULL){
		printf("No such file.\n");
		return 0;
	}

	for(i=0; !feof(fptr); i++) fscanf(fptr, "%c", &string[i]);
	
	printf("String from the file: \n%s", string);
	printf("\nThe number of characters in the string: %d\n", char_count(string));

	return 0;

}
