#include<stdio.h>
#include<stdlib.h>
#include "header.h"

typdef struct array{
int* arr;
}array;

int** get_arrays(int total_size){
		
	int arr[total_size];	//to store the sizes of all arrays
	int* all_sizes = arr;

	int** total_ptr = (int**)malloc(total_size * sizeof(int));

	//Creating an array of pointers, so every index can store one address 
	int* array_ptr[total_size];
	int i, j;

	for (i=0; i<total_size; i++){
	
		int size_of_array;
		printf("Enter the size of Array%d:\n", i+1);
		scanf("%d", &size_of_array);
		
		arr[i] = size_of_array;
		total_ptr = &array_ptr[i];
		total_ptr++;
		
		for (j=0; j<size_of_array; j++){
		
			printf("Enter the elements of the array:\n");
			scanf("%d", array_ptr[i]+j);	
		}
	}
	
	//for storing the array of sizes
	total_ptr++;
	total_ptr = &all_sizes;

	return total_ptr;	
}
