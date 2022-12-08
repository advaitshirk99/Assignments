#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
  int a, pid, ppid;
  pid = getpid();
  ppid = getppid();
  printf("Parent process\n");
  printf("ID: %d\n", pid);
  printf("This process' parent ID: %d\n", ppid);
  a = fork();
  printf("test\n");

  if(a == 0){
    wait(NULL);
    pid = getpid();
    ppid = getppid();
    printf("Inside child process\n");
    printf("ID: %d\n", pid);
    printf("This process' parent ID: %d\n", ppid);

  }
  else if(a > 0){
    pid = getpid();
    ppid = getppid();
    printf("Inside original parent process\n");
    printf("ID: %d\n", pid);
    printf("This process' parent ID: %d\n", ppid);
  }
}
