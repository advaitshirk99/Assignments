#include<stdio.h>
#include<stdlib.h>

#include "header.h"

int main(int argc, char* argv[]){

	int i, arr[10], arr_sum, arr_prod;
	float arr_avg;

	for(i=0; i<10; i++){
		arr[i] = atoi(argv[i+1]);
	}

	arr_sum = sum(arr);
	arr_avg = average(arr);
	arr_prod = product(arr);

	printf("The sum is: %d\nThe average is:%f\nThe product is:%d\n", arr_sum, arr_avg, arr_prod);

	return 0;
}