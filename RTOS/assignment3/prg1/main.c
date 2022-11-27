#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t childpid;
    childpid = fork();
    if(childpid == -1){
        perror("Failed to fork");
        return 1;
    }
    if(childpid ==0){
        printf("I am child\n"); //Child node
    }
    else{
        printf("I am parent\n"); //Parent node
    }
    return 0;
}