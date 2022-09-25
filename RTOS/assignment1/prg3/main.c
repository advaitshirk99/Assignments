#include "header.h"
#include<stdio.h>

int main(){
	
	FILE* ptr = fopen("abc.txt", "r");
	if (ptr == NULL){
		printf("No such file.\n");
		return 0;
	}


}
