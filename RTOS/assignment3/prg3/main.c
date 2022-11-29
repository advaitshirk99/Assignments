#include<stdio.h>
#include<unistd.h>

int main(){
	int sum = 0, i, n, num, fork_val;
	fork_val=fork();

	if(fork_val == 0){
		printf("Enter the value of n:\n");
		scanf("%d", &n);
		int arr[n];
		for(i=0; i<n; i++){
			scanf("%d", &arr[i]);
		}
		for(i=0; i<n; i++){
			sum += arr[i];
		}
		printf("Sum is: %d\n", sum);
	}
	return 0;
}