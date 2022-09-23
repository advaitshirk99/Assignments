#define MAX_LINE_LENGTH 1000
#include<stdio.h>
#include<stdlib.h>

int give_words(char arr[]){
	
	int i, word_count =0;
	for(i=0; arr[i] != '\0'; i++){
		if(arr[i] == ' ' && arr[i+1] != ' '){
			word_count++;
		}
	}
	return word_count;
}

int *give_lines(char arr[], FILE* ptr, int *result){

	int line_count=0, word_count=0;

	while (fgets(arr, MAX_LINE_LENGTH, ptr)){
		word_count += give_words(arr);
		line_count++;
	}
	*(result) = line_count;
	*(result+1) = word_count;
	return result;
}

int main(){

	int i, word_count=0, line_count=0;        
	FILE* ptr = fopen("abc.txt", "r");
	char line[MAX_LINE_LENGTH];
	
        if (ptr == NULL){
                printf("No such file.\n");
                return 0;
        }

	int *final_result, *result;
	result = malloc(2 * sizeof(int));
	final_result = give_lines(line, ptr, result);	
	printf("Line count: %d\nWord Count: %d\n", result[0], result[1]);
	
	free(result);
	return 0; 
}
