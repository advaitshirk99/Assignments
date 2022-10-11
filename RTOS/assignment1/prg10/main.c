#include<stdio.h>
#include "header.h"
#include<stdlib.h>

int main(){

        FILE* source = fopen("input.txt", "r");
        FILE* destination = fopen("output.txt", "w");

        if (source == NULL){

                printf("No source file\n");
                exit(0);
        }
        else if (destination == NULL){

                printf("No destination file\n");
                exit(0);
        }
        
        lower_to_upper(source, destination);

	fclose(source);
	fclose(destination);

	return 0;
}
