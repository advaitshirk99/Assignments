#include<stdio.h>
#include<stdlib.h>
#include "header.h"

void append_file(char source1[], char source2[], char destination[]){

	FILE *src1 = fopen(source1, "r");
	FILE *src2 = fopen(source2, "r");
	FILE *dest = fopen(destination, "a+");
	char buffer[100];

    if (src1 == NULL){
        printf("No source1 file\n");
        exit(0);
    }
    else if (src2 == NULL){
        printf("No source2 file\n");
        exit(0);
    }
    else if (dest == NULL){
    	printf("No destination file\n");
    	exit(0);
    }

    //Contents of source1 will start from new line destination
    fprintf(dest, "\n");
    while (!feof(src1)){
    	fscanf(src1, "%s", buffer);
    	fprintf(dest, "%s", buffer);
    }

    //Contents of source2 will start from new line in destination
    fprintf(dest, "\n");
    while (!feof(src2)){
    	fscanf(src2, "%s", buffer);
    	fprintf(dest, "%s", buffer);
    }

    fclose(src1);
    fclose(src2);
    fclose(dest);
}