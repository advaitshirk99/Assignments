#include<stdio.h>
#include "header.h"
#include<stdlib.h>
int main(){

        //Taking the total number of students' data to be taken
     	int student_count;
        printf("Enter how many students' data needs to be added:\n");
        scanf("%d", &student_count);
	
	//Creating 'student_count' number of variables, called 'student', of type 'students'
	students student[student_count];
	
	//Creating a pointer which will point to the data of qualified students	
	int* qualifying_candidates = (int*)malloc(student_count * sizeof(int)); 
	int qualifying_count;

	qualifying_count = get_data(student, student_count, qualifying_candidates);

	display_result(student, qualifying_candidates, qualifying_count);

	return 0;
}
