#include<stdio.h>
#include<unistd.h>

int main(){
	//Creating first child
	int n1 = fork();

	//Creating 2nd child, but first child also executes this line and creates a grandchild
	int n2 = fork();

	if(n1>0 && n2>0){
		printf("Parent\n");
		printf("%d %d\n", n1, n2);
		printf("My id is %d\n\n", getpid());
	}

	else if(n1 == 0 && n2>0){
		printf("First child\n");
		printf("%d %d\n", n1, n2);
		printf("My id is %d\n\n", getpid());
	}

	else if(n1>0 && n2 == 0){
		printf("Second child\n");
		printf("%d %d\n", n1, n2);
		printf("My id is %d\n\n", getpid());
	}
	
	else{
		printf("Third child\n");
		printf("%d %d\n", n1, n2);
		printf("My id is %d\n\n", getpid());
	}
	return 0;
}