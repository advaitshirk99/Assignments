#include<stdio.h>
void remove_duplicates(FILE *source1, FILE *source2, FILE *destination);

typedef struct store{
	char word[20];
	int duplicate;
}store;