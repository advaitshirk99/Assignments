#include<stdio.h>
#include "header.h"

int main(){

	int array_count;
	printf("Enter the total number of arrays to be accepted:\n");
	scanf("%d", &array_count);

	int i, size_array[array_count];
	printf("\nEnter the sizes of the %d arrays that are to be accepted:\n", array_count);
	for (i=0; i<array_count; i++) scanf("%d", &size_array[i]);
	
	int data_array[array_count][1000];
	
	get_data(data_array, size_array, array_count);
	printf("\n\n");
	display_result(data_array, size_array, array_count);

	return 0;
}
