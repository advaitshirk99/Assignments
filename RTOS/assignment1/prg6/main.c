#include<stdio.h>
#include "header.h"
#include<stdlib.h>

int main(int argc, char* argv[]){
	
	FILE* source = fopen(argv[1], "r");
	FILE* destination = fopen(argv[2], "w");

	if (source == NULL){
	
		printf("No source file\n");
		exit(0);
	}
	else if (destination == NULL){
	
		printf("No destination file\n");
		exit(0);
	}
	
	copy_text(source, destination);
	printf("Contents copied to %s\n", argv[2]);

	fclose(source);
	fclose(destination);

	return 0;
}
