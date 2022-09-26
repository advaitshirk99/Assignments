#include "header.h"
#include<stdlib.h>
#include<stdio.h>

int place_words(char arr[], int word_count, FILE* odd_file, FILE* even_file){
	 
	int i;	
	char space[]=" ";
	
	for(i=0; arr[i] != '\0'; i++){
		
		if (arr[i] != ' ' && (word_count % 2) == 0){
			fputc(arr[i], odd_file);
		}
		
		if (arr[i] != ' ' && (word_count % 2) != 0){
			fputc(arr[i], even_file);
		}
		if(arr[i] == ' ' && arr[i+1] != ' '){
			word_count++;
			fputc(space[0], even_file);
			fputc(space[0], odd_file);
		}
	}

	return word_count;
}

void segregate_words(char arr[], FILE* ptr, char *argv[]){

	int word_count=0;
	
	FILE* even_file;
        FILE* odd_file;
 
 	even_file = fopen(argv[3], "w");
	odd_file = fopen(argv[2], "w");

	while (fgets(arr, MAX_LINE_LENGTH, ptr)){
		word_count += place_words(arr, word_count, odd_file, even_file); 
	}

	fclose(even_file);
	fclose(odd_file);
}
