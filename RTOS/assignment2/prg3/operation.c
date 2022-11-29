#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LINE_LENGTH 1000

void compare_lines(char source1[], char source2[]){

	FILE *src1 = fopen(source1, "r");
	FILE *src2 = fopen(source2, "r");
    char buffer1[MAX_LINE_LENGTH], buffer2[MAX_LINE_LENGTH];

	if (src1 == NULL){
        printf("No source1 file\n");
        exit(1);
    }
    else if (src2 == NULL){
        printf("No source2 file\n");
        exit(1);
    }

    while(!feof(src1)){
        fgets(buffer1, MAX_LINE_LENGTH, src1);
        while(!feof(src2)){
            fgets(buffer2, MAX_LINE_LENGTH, src2);

            if((strcmp(buffer1, buffer2))!=0){
                printf(buffer1);
                printf(buffer2);
            }
        }
    }
}