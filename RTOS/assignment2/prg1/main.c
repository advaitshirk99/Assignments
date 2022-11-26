#include<stdio.h>
#include "header.h"

int main(){

	FILE *source1 = fopen("source1.txt", "r");
	FILE *source2 = fopen("source2.txt", "r");
	FILE *destination = fopen("destination.txt", "w");

	remove_duplicates(source1, source2, destination);

	fclose(source1);
	fclose(source2);
	fclose(destination);
	return 0;
}