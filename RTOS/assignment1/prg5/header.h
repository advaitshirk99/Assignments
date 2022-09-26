#define MAX_LINE_LENGTH 1000
#include<stdio.h>

int place_words(char arr[], int count, FILE* odd_file, FILE* even_file);
void segregate_words(char arr[], FILE* ptr, char *argv[]);
