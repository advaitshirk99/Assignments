#include<stdio.h>
#include "header.h"
#include<string.h>

int main(){
    printf("Enter the total number of files to be printed:\n");
    int total, i;
    scanf("%d", &total);
    file_name name_arr[total];
    char buffer[25];
    printf("\nEnter the name of the files:\n");
    for(i=0; i<total; i++){
        scanf("%s", buffer);
        strcpy(name_arr[i].name, buffer); 
    }

    printf("The contents of the files are:\n\n");
    for(i=0; i<total; i++){
        print_file(name_arr[i].name, i+1);
    }
}