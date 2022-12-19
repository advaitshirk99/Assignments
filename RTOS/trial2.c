#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MAX 10
int main()
{
  
  int fd[2], i = 0,sum=0;
  pipe(fd);//pipe
  pid_t pid = fork();

   if( pid > 0 ) {
      int arr[100];
      printf("enter 10 numbers\n");
      for(i=0;i<10;i++)
      {
        scanf("%d",&arr[i]);
      }
  
      
      close(fd[0]); //close starting end of pipe
  
          
      write(fd[1], arr, sizeof(arr));//writing to the memory
      exit(0);
      
  }
  
  
   else if(pid == 0) {
      wait(NULL);
  
      
  
      close(fd[1]);
  
       
      int arr[100];
  
     
      int n = read(fd[0], arr, sizeof(arr));
      printf("The numbers are \t");
      for ( i = 0;i < 10; i++)
        {
         // printing the array received from parent process
          printf("%d ", arr[i]);
        }
      for ( i = 0;i < 10; i++)
      {
        
        sum=sum+arr[i];
      }
      printf("%d",sum);
  }



 else {
      perror("error\n");
  }
}