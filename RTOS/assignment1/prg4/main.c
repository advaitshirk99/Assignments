#define MAX_LINE_LENGTH 1000
#include<stdio.h>

int main(){

	int i, word_count=0, line_count=0;        
	FILE* ptr = fopen("abc.txt", "r");
	char line[MAX_LINE_LENGTH];
	
        if (ptr == NULL){
                printf("No such file.\n");
                return 0;
        }

	while (fgets(line, MAX_LINE_LENGTH, ptr)){
		for(i=0; line[i] != '\0'; i++){
			if(line[i] == ' ' && line[i+1] != ' '){
				word_count++;
			}
		}
		line_count++;
	}

	printf("Line count: %d\nWord Count: %d\n", line_count, word_count );

	return 0; 
}
