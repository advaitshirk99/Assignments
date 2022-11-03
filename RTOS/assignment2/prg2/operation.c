#include<stdio.h>
#include<stdlib.h>
#include "header.h"

void append_file(char source1[], char source2[], char destination[]){

	FILE *src1 = fopen(source1, "r");
	FILE *src2 = fopen(source2, "r");
	FILE *dest = fopen(destination, "a+");
	char buffer[100], punct;

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
    while (!feof(src1)){
<<<<<<< HEAD
    	fscanf(src1, "%s", buffer);
        //if(src1 == '\n') fprintf(dest, "\n");
    	fprintf(dest, "%s ", buffer);
=======
    	fscanf(src1, "%s%c", buffer, &punct);
        if(punct == '\n') fprintf(dest, "\n");
    	else fprintf(dest, "%s%c", buffer, punct);
>>>>>>> 3a45438f92a10e6de58cec95d4817ed8239a6362
    }

    //Contents of source2 will start from new line in destination
    fprintf(dest, "\n");
    while (!feof(src2)){
<<<<<<< HEAD
    	fscanf(src2, "%s", buffer);
        //if (src2 == "\n") fprintf(dest, "\n");
    	fprintf(dest, "%s ", buffer);
=======
        fscanf(src2, "%s%c", buffer, &punct);
        if(punct == '\n') fprintf(dest, "\n");
        else fprintf(dest, "%s%c", buffer, punct);
>>>>>>> 3a45438f92a10e6de58cec95d4817ed8239a6362
    }

    fclose(src1);
    fclose(src2);
    fclose(dest);
}