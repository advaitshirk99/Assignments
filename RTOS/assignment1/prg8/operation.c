#include<stdio.h>
#include "header.h"

void get_data(int data_array[][1000], int size_array[], int array_count){

	int i, j;

	for (i=0; i<array_count; i++){

	        printf("\nEnter the elements of array%d:\n", i+1);

		for (j=0; j<size_array[i]; j++){
			
			scanf("%d", &data_array[i][j]);
		}
	}
}

void display_result(int data_array[][1000], int size_array[], int array_count){

	int i, j;
	for(i=0; i<array_count; i++){
		
		int k=0, l=0, even[size_array[i]], odd[size_array[i]];

		for (j=0; j<size_array[i]; j++){
			
			if (data_array[i][j] % 2 ==0){
				
				even[k++] = data_array[i][j];
			}

			else{
			
				odd[l++] = data_array[i][j];
			}
				
		}
		k--;
		l--;
		
		printf("Even elements of Array%d are:\n", i+1);
		while (k >= 0){ 

			printf("%d ", even[k--]);
		}
		printf("\n");

		printf("Odd elements of Array%d are:\n", i+1);
		while (l >= 0){
			
			printf("%d ", odd[l--]);
		}
		printf("\n\n");
	}
}

