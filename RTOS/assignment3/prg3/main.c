#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
	int sum = 0, i, n, num, fork_val, arr[10];
	pid_t abc;

	abc=fork();
	wait(NULL);
	if(abc == 0){
		for(i=0; i<n; i++){
			sum += arr[i];
		}
		printf("Sum is: %d\n", sum);

	}

	else if(abc>0){
		printf("Enter the value of n:\n");
		for(i=0; i<n; i++){
			scanf("%d", &arr[i]);
		}
		exit(0);
	}
	return 0;
}