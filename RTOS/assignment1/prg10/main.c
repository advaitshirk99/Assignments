#include<stdio.h>
#include<stdlib.h>
#include "header.h"

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
	
	printf("works1");	
	char buffer[510];
	printf("works2");
	read_file(source, destination, buffer);
	
	fclose(source);
	fclose(destination);
	return 0;
}
