#include<stdio.h>
#include "header.h"
#include<stdlib.h>

void display_data(char branch[], char name[], int id){

	printf("%s\t%s\t%d\n", branch, name, id);
}

void get_data(students student[], int student_count){

	int i, k, qualifying_students[student_count], total_eligible =0;
	for (i=0; i<student_count; i++){
		
		printf("Enter the details of student%d:\n",i+1);
		printf("Branch: ");
		scanf("%s", student[i].branch);	
                printf("Name: ");     
                scanf("%s", student[i].name);
                printf("ID: ");     
                scanf("%d", &student[i].id);
                
		int j, count=0;
		for (j=0; j<5; j++){
			
			printf("Marks in Subject%d: ", j+1);     
                	scanf("%d", &student[i].subject.subject_marks[j]);

			if (student[i].subject.subject_marks[j] > 80) count++;
		}
		
		if (count ==5){ 
			//Use a pointer here, point it to the count and qualifying_students. Then return it from this function to the main, and pass it to the display function, again in main.
			total_eligible++;
			qualifying_students[k++] = i;
		}
	}
	printf("\n");
}

void display_data(students student[], int ){

	int i;
	for (i=0; i<student_count; i++){
		
		printf("Details of the qualifying students:\n");
			
	}
}
