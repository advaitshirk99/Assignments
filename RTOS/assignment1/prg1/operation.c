#include "header.h"
#include<stdio.h>

//Function to compute the sum
int sum(int arr[]){

	int i, sum=0;
	for(i=0; i<10; i++){
		sum += arr[i];
		printf("sum:%d\n", sum);
	}
	return sum;
}

//Function to compute the average
int average(int arr[]){

	float avg;
	avg = sum(arr)/10;
	return avg;
}

//Function to compute the product
int product(int arr[]){

	int i, prod=1;
	for(i=0; i<10; i++){
		prod *= arr[i];
	}
	return prod;
}
