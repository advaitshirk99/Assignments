#include<stdio.h>
#include "header.h"
#include<stdlib.h>

int main(int argc, char* argv[]){
	
	int i;
	char line[MAX_LINE_LENGTH];
	FILE* ptr = fopen(argv[1], "r");

	if (ptr == NULL){
		printf("No such file.\n");
		return 0;
	}

	segregate_words(line, ptr, argv);
	
	fclose(ptr);

	return 0;
}
