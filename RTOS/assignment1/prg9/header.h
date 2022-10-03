typedef struct subject {

        int subject_marks[5];
}subjects;

typedef struct student {

	char branch[10];
	char name[15];
	int id;
	subjects subject;
}students;

void get_data(students student[], int student_count);
void display_data(char branch[], char name[], int id);
