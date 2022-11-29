#include<stdio.h>

typedef struct processes{
	int arrival_time;
	int burst_cycle;
	int priority;
	int waiting_time;
	int turn_around_time;
}process_data;

int min(process_data p[], int choice){
	int i, total, index;
	total = (sizeof(p)/sizeof(p[0]))
	if(choice == 0){
		int minimum = p[0].arrival_time;
		for(i=0; i<total; i++){
			if(minimum>p[i].arrival_time){
				minimum = p[i].arrival_time;
				index = i;
			}
		}
	}
	if(choice == 1){
		int minimum = p[0].burst_cycle;
		for(i=0; i<total; i++){
			if(minimum>p[i].burst_cycle){
				minimum = p[i].burst_cycle;
			}
		}
	}
	if(choice == 2){
		int minimum = p[0].priority;
		for(i=0; i<total; i++){
			if(minimum>p[i].priority){
				minimum = p[i].priority;
			}
		}
	}
	return minimum
}

void input_pdata(process_data p){
	printf("Enter the arrival time of this process: ");
	scanf("%d", &(p.arrival_time));
	printf("Enter the burst cycle of this process: ");
	scanf("%d", &(p.burst_cycle));
}

void fcfs(process_data p[]){

}

int total_waiting_time(){}