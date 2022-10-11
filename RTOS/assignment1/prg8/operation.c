#include<stdio.h>
#include "header.h"

//Function to store the elements of all the arrays given by the user
void get_data(int data_array[][1000], int size_array[], int array_count){

	int i, j;

	for (i=0; i<array_count; i++){

	        printf("\nEnter the elements of array%d:\n", i+1);

		for (j=0; j<size_array[i]; j++){
			
			scanf("%d", &data_array[i][j]);
		}
	}
}

//Function to display the odd and even elements of all the arrays
void display_result(int data_array[][1000], int size_array[], int array_count){

	int i, j;
	for(i=0; i<array_count; i++){
		
		//In every iteration, the even and odd arrays are initialized as per the max size of that particular array
		int k=0, l=0, even[size_array[i]], odd[size_array[i]];

		for (j=0; j<size_array[i]; j++){
			
			//Condition for even number; if true, storing it in even array
			if (data_array[i][j] % 2 ==0){
				
				even[k++] = data_array[i][j];
			}
			
			//Condition for odd number; if true, storing it in the odd array
			else{
			
				odd[l++] = data_array[i][j];
			}
				
		}
		//Decrementing because k and l will be incremented in the last iteration of the upper loop, but those indexes will store no values
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

