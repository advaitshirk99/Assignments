#include<stdio.h>
#include "header.h"
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//Function to change the word from lower case to upper case
char* change_case(char arr[]){
	
	int i, size = strlen(arr);
	for(i=0; i<size; i++){
		
		arr[i] = toupper(arr[i]);
	}

	return arr;
}

//Function to get the punctuation attached to a word
char return_punctuation(char arr[]){

	int i, size = strlen(arr);
	char e;
	
	for (i=0; i<size; i++){
		if(ispunct(arr[i])){
			e = arr[i];	//Storing the punctuation to return it later		
			arr[i]= '\0';	//Ending the char array here with the null character
			return e;
		}
	}
}

//Function to read the file, and change the selected words into uppercase
void lower_to_upper(FILE* source, FILE* destination){
	
	int i;	
	char punctuation, read[20], words[][20] = {"Manipal", "Udupi", "miss", "names"};
	while(!feof(source)){

		fscanf(source, "%s", read);
		
		punctuation = return_punctuation(read);	
		int flag =0;

		for (i=0; i<4; i++){

			if(strcmp(read, words[i]) == 0) {
				if(ispunct(punctuation)){
					fprintf(destination, "%s%c ", change_case(read), punctuation);
				}
				else fprintf(destination, "%s ", change_case(read));	 	
				flag =1;
			}
		}

		if (flag == 1) continue;
		
		else{
			if(ispunct(punctuation)){
				fprintf(destination, "%s%c ", read, punctuation);
			}
			else{
				fprintf(destination, "%s ", read);	
			}
		}
	}
}
