#include<stdio.h>
#include<string.h>
#include "header.h"
#include<stdlib.h>

void write_word(char arr[], char* words[], FILE* destination){

        int i, j, count=0;
        char word[20];

        for (i=0; arr[i] != '\0'; i++){

                if (arr[i] != ' '){

                        word[i]= arr[i];
                        count++;

                        if (strcmp(word, (words[0])) == 0){
				
				for(j=0; j<count; j++){
                                        fputc(word[j]-32, destination);
                                }
			}
			else if (strcmp(word, (words[1])) == 0){
				for(j=0; j<count; j++){
                                        fputc(word[j]-32, destination);
                                }
			}
			else if (strcmp(word, (words[2])) == 0){

				for(j=0; j<count; j++){
                                        fputc(word[j]-32, destination);
                                }
			}
			else if (strcmp(word, (words[3])) == 0){

                                for(j=0; j<count; j++){
                                        fputc(word[j]-32, destination);
                                }
                        }
                        else{

                                fputc(arr[i], destination);
                        }

                        count =0;
        	}
	}
}


void read_file(FILE* source, FILE* destination, char buffer[]){

	char* words[] = {"Manipal", "miss", "Udupi", "names"};

	while (fgets(buffer, 300, source) != NULL){
		write_word(buffer, words, destination);
	}

}
