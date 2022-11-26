#include "header.h"
#include<stdio.h>
#include<string.h>

int word_count(FILE *source){

	char temp[20];
	int count=0;
	while(!feof(source)){

		fscanf(source, "%s", temp);
		if(temp != '\0'){
			count++;
		}
	}
	rewind(source);
	return count;
}

void remove_duplicates(FILE *source1, FILE *source2, FILE *destination){

	char word1[20], word2[20];
	int count, check=0, i=0;
	count = word_count(source2);
	store s2words[count];								//Structure that will store words from file 2

	while(!feof(source1)){
		fscanf(source1, "%s", word1);

		while(!feof(source2)){
			fscanf(source2, "%s", word2);
			strcpy((s2words[i]).word, word2);			//Store words from file to in structure store
			if((strcmp(word1, word2)) ==0){
				(s2words[i]).duplicate = 1;				//s2words.duplicate set to 1 if word is duplicate
				check++;
			}
			else (s2words[i]).duplicate = 0;			
			i++;
		}

		if(check ==0) fprintf(destination, "%s ", word1);	//If no duplicates were found, print word in destination
	}

	for(i=0; i<count; i++){
		if(s2words[i].duplicate == 0) fprintf(destination, "%s ", (s2words[i]).word);	//Print all words that were not duplicates, from 2nd file
	}
	printf("Duplicates removed!\n\n");
}
