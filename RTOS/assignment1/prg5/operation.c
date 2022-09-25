#include "header.h"
#include<stdlib.h>
#include<stdio.h>

int place_words(char arr[], int count, char *argv[]){
	 
	int i;	
	FILE* even_file;
	FILE* odd_file;
	char space[]=" ";
	
	even_file = fopen(argv[3], "w");
	odd_file = fopen(argv[2], "w");

	for(i=1; arr[i] != '\0'; i++){
		
		if (arr[i] != ' ' && count % 2 == 0){
			fputc(arr[i], odd_file);
		}
		
		if (arr[i+1] != ' ' && count % 2 != 0){
			fputc(arr[i], even_file);
		}
		if(arr[i+1] == ' '){
			count++;
			fputc(space[0], even_file);
			fputc(space[0], odd_file);
		}
	}

	fclose(even_file);
	fclose(odd_file);
	return count;
}

void segregate_words(char arr[], FILE* ptr, char *argv[]){

	int count=0;
	while (fgets(arr, MAX_LINE_LENGTH, ptr)){
		count += place_words(arr, count, argv); 
	}
}
