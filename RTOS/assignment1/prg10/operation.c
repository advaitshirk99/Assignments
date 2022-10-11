#include<stdio.h>
#include "header.h"
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char* change_case(char arr[]){
	
	int i, size = strlen(arr);
	for(i=0; i<size; i++){
		
		arr[i] = toupper(arr[i]);
	}

	return arr;
}

void return_punctuation(char arr[]){

	int i, size = strlen(arr);

	for (i=0; i<size; i++){
		
		if(ispunct(arr[i])){
			
			arr[i]= '\0';
		}
	}
}

void lower_to_upper(FILE* source, FILE* destination){
	
	char read[20], words[][20] = {"Manipal", "Udupi", "miss", "names"};
	while(!feof(source)){
			
		fscanf(source, "%s", read);
		
		return_punctuation(read);	

		if(strcmp(read, words[0]) == 0) {
			
			fprintf(destination, "%s ", change_case(read));
			fscanf(source, "%s", read);
		}

		if(strcmp(read, words[1]) == 0) { 

                        fprintf(destination, "%s ", change_case(read));
			fscanf(source, "%s", read);
		}
		
		if(strcmp(read, words[2]) == 0) { 

                        fprintf(destination, "%s ", change_case(read));
			fscanf(source, "%s", read);
		}

		if(strcmp(read, words[3]) == 0) { 

                        fprintf(destination, "%s ", change_case(read));
		}

		else{
			fprintf(destination, "%s ", read);
		}
	}
}
