#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main(){
	//check all_data[2]
	int** all_data, total_size;
	printf("Enter the total number of arrays to be entered:\n");
	scanf("%d", &total_size);

	//The last location of the all_data will contain the array of sizes of all the arrays
	all_data = get_arrays(total_size);
	
	int i, j;
	for (i=0; i<total_size; i++){
	
		printf("Array%d is:\n", i+1);
		for(j=0; j< *(*(all_data+total_size)+i); j++){
		
			printf("%d ", *(*(all_data+i)+j));
		}
		printf("\n");
	}	
	
	free(all_data);
	return 0;
}

