#include<stdio.h>
#include "header.h"

int main(){

	int array_count;
	printf("Enter the total number of arrays to be accepted:\n");
	scanf("%d", &array_count);
	
	//Storing the sizes of all arrays in an array
	int i, size_array[array_count];
	printf("\nEnter the sizes of the %d arrays that are to be accepted:\n", array_count);
	for (i=0; i<array_count; i++) scanf("%d", &size_array[i]);
	
	//This creates a array_count x 1000 2D matrix, in which all the elements of all the arrays would be stored
	int data_array[array_count][1000];
	
	get_data(data_array, size_array, array_count);
	printf("\n\n");
	display_result(data_array, size_array, array_count);

	return 0;
}
