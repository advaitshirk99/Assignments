#include<stdio.h>
#include "header.h"
#include<stdlib.h>
#include<string.h>

void lower_to_upper(FILE* source, FILE* destination){
	
	char read[100], words[][20] = {"Manipal", "Udupi", "miss", "names"};
	char replace[][20] = {"MANIPAL", "UDUPI", "MISS", "NAMES"};
	
	//If continue is used after every 'if', it won't check for other words in the words array. If continue used only on the last if, every word repeats
	while(!feof(source)){
	
		fscanf(source, "%s", read);
		if(strcmp(read, words[0]) == 0) {
			
			fprintf(destination, "%s ", replace[0]);
		}

		if(strcmp(read, words[1]) == 0) { 

                        fprintf(destination, "%s ", replace[1]);
		}
		
		if(strcmp(read, words[2]) == 0) { 

                        fprintf(destination, "%s ", replace[2]);
		}

		if(strcmp(read, words[3]) == 0) { 

                        fprintf(destination, "%s ", replace[3]);
			continue;
		}

		else{
			fprintf(destination, "%s ", read);
		}
	}
}
