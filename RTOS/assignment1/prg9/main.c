#include<stdio.h>
#include "header.h"

int main(){

        //Taking the total number of students' data to be taken
       
	int student_count;
        printf("Enter how many students' data needs to be added:\n");
        scanf("%d", &student_count);

	students student[student_count];
	
	get_data(student, student_count);

	return 0;
}
