#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int split;
	split =  fork();

	if(split == 0){
		FILE *child_file = fopen("cfile.txt", "w");
		fprintf(child_file, "%s", "I am student of MSIS. And I am good");
	}
	else if(split > 0){
		FILE *parent_file = fopen("pfile.txt", "w");
		fprintf(parent_file, "%s", "I am in manipal enjoying the environment of manipal.. and MSIS campus is very nice");
	}
	else exit(1);
}