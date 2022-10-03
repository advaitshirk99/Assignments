#include<stdio.h>
#include "header.h"
#include<stdlib.h>

int get_data(students student[], int student_count, int* qualifying_candidates){

	int i, k=0, qualifying_students[student_count], eligible_candidates=0;
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
		printf("\n");

		if (count ==5){ 
			//Use a pointer here, point it to the count and qualifying_students. Then return it from this function to the main, and pass it to the display function, again in main.
			qualifying_students[k++] = i;
			eligible_candidates++;
		}
	}
	printf("\n");
	
	qualifying_candidates = qualifying_students;

	return eligible_candidates;
}

void display_result(students student[], int* qualifying_candidates, int qualifying_count){

	int i;
	printf("Details of the qualifying students are:\n");
	
	for (i=0; i<qualifying_count; i++){
			
		printf("Branch: %s\tName: %s\tID: %d\n", student[*(qualifying_candidates+i)].branch, student[*(qualifying_candidates+i)].name, student[*(qualifying_candidates+i)].id);
		}
}

