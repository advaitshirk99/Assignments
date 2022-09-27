#include "header.h"
#include<stdio.h>

int sum(int arr[]){

	int i, sum=0;
	for(i=0; i<10; i++){
		sum += arr[i];
		printf("sum:%d\n", sum);
	}
	return sum;
}

int average(int arr[]){

	float avg;
	avg = sum(arr)/10;
	return avg;
}

int product(int arr[]){

	int i, prod=1;
	for(i=0; i<10; i++){
		prod *= arr[i];
	}
	return prod;
}
