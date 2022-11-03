void compare_lines(char source1[], char source2[]){

	FILE *src1 = fopen(source1, "r");
	FILE *src2 = fopen(source2, "r");
	char buffer[50];

	if (src1 == NULL){
        printf("No source1 file\n");
        exit(0);
    }
    else if (src2 == NULL){
        printf("No source2 file\n");
        exit(0);
    }
    else if (dest == NULL){
    	printf("No destination file\n");
    	exit(0);
    }

    //Compare word by word
    while(!feof(src1)){
    	fscanf(src1, "%s", buffer);
    	
    	
    }
}