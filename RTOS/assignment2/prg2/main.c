#include<stdio.h>
#include "header.h"

int main(){
	
	char src1[50];
	printf("Enter the name of source 1: ");
	scanf("%s", src1);

	char src2[50];
	printf("\nEnter the name of source 2: ");
	scanf("%s", src2);

	char dest[50];
	printf("\nEnter the name of destination: ");
	scanf("%s", dest);

	append_file(src1, src2, dest);

	return 0;
}