#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main(){
	
	FILE* source;
       	source	= fopen("input.txt", "r");
	FILE* destination; 
	destination = fopen("output.txt", "w");

	if (source == NULL){
	
		printf("No source file\n");
		exit(0);
	}
	else if (destination == NULL){
	
		printf("No destination file\n");
		exit(0);
	}
	char buffer[510];
	read_file(source, destination, buffer);
	
	fclose(source);
	fclose(destination);
	return 0;
	}
