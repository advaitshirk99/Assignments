#include<stdio.h>
#include "header.h"
#include<stdlib.h>

int main(int argc, char* argv[]){

	FILE* ptr = fopen(argv[1], "w");

	if (ptr == NULL){
		
		printf("No output file\n");
		exit(0);
	}	

	store_string(ptr);

	fclose(ptr);

	return 0;
}
