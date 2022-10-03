typedef struct subject {

        int subject_marks[5];
}subjects;

typedef struct student {

	char branch[10];
	char name[15];
	int id;
	subjects subject;
}students;

int get_data(students student[], int student_count, int* qualifying_candidates);
void display_result(students student[], int* qualifying_candidates, int qualifying_count);
