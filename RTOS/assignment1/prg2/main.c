#include "header.h"
#include<stdio.h>

int main(){
	
	int i=0, arr[1000], arr_sum=0, arr_prod=1;
	float arr_avg=0, count=1.0;

	while(1){
		printf("Enter the number:\n");
		scanf("%d", &arr[i]);
		if(arr[i] == 888) return 0;
		
		arr_sum = sum(arr[i], arr_sum);
		arr_avg = average(arr_sum, count);
		count +=1;
		arr_prod = product(arr[i], arr_prod);
		
		printf("Sum: %d\tAverage: %.2f\tProduct: %d\n", arr_sum, arr_avg, arr_prod);
		i++;
		
}
	return 0;
}
