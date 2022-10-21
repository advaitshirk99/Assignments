#include "header.h"
#include<stdio.h>
#include<string.h>

void remove_duplicates(FILE* source1, FILE* source2, FILE* destination){

	char word1[20], word2[20];
	
	while(!feof(source1)){
		fscanf(source1, "%s", word1);
		while(!feof(source2)){

			fscanf(source2, "%s", word2);

			if(strcmp(word1, word2)!=0){
				fprintf(destination, "%s %s ", word1, word2);
			}
		}
	}
}
