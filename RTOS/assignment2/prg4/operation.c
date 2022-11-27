#include "header.h"
#include<stdio.h>
#define MAX_LINE_LENGTH 1000

void print_file(char source[25], int i){
    FILE *src = fopen(source, "r");
    int first_line=0;
    char buffer[MAX_LINE_LENGTH];
    while(!feof(src)){
        fgets(buffer, MAX_LINE_LENGTH, src);
        if(first_line == 0){
            printf("TITLE: %s\n", buffer);
            first_line = 1;
        }
        else{
            printf("%s\n", buffer);
        }
    }
    printf("\nPAGE NO: %d\n", i);
    printf("*********************************************************************************************************************************************\n\n");
    fclose(src);
}

