#include<stdio.h>
#include<unistd.h>

int main(){
	int sum = 0, i, n, num;
	printf("Enter the value of n:\n");
	scanf("%d", &n);
	int arr[n];
	for(i=0; i<n; i++){
		scanf("%d", &num);
		arr[i] = num;
	}
	n=fork();

	if(n == 0){
		for(i=0; i<10; i++){
			sum += arr[i];
		}
		printf("Sum is: %d", sum);
	}

	return 0;
}