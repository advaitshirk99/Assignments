#include<stdio.h>
#include "mystring.h"

int check_palindrome(char* str){
    char *ptr, *rev;
    ptr = str;
    while (*ptr != '\0'){
        ++ptr;
    }
    --ptr;
 
    for (rev = str; ptr >= rev;) {
        if (*ptr == *rev) {
            --ptr;
            rev++;
        }
        else
            break;
    }
		
		if(rev>ptr) return 0;
		else return 1;
}
