#include<stdio.h>
#include<unistd.h>
#include "functions.h"

int main(){
	int total, i;
	float total_wt =0, total_tt=0;
	printf("Enter number of processes to be considered: ");
	scanf("%d", &total);
	process_data process[total];
	for(i=0; i<total; i++){
		input_pdata(process[i], i);
	}
	int split = fork();
	if(split == 0){
		fcfs(process);
	}
	for(i=0; i<total; i++){
		total_wt +=	process[i].waiting_time;
		total_tt += process[i].turn_around_time;  
	}
	printf("FOR FCFS:\nAverage waiting time: %0.2f\nAverage turnaround time: %0.2f\n",(total_wt/(float)total), (total_tt/(float)total));

}
