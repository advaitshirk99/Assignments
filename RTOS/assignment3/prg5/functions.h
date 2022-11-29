#include<stdio.h>

typedef struct processes{
	int arrival_time;
	int burst_cycle;
	int priority;
	int same_at;
	int same_bc;
	int waiting_time;
	int turn_around_time;
}process_data;

int min(process_data p[], int choice, int i){
	int total, index, j, original_index=i;
	total = (sizeof(p)/sizeof(p[0]));
	if(choice == 0){
		int minimum = p[i].arrival_time;
		for(i=i; i<total; i++){
			if(minimum>p[i].arrival_time){
				minimum = p[i].arrival_time;
				index = i;
			}
			for(j=i; j<total-1; j++){
				if(p[i].arrival_time == p[j].arrival_time){
					p[i].same_at = p[i].arrival_time;							//Setting same_at as arrival time, to identify multiple processes with same arrival time
					p[j].same_at = p[i].arrival_time;
				}
			}
		}
		for(i=original_index; i<total; i++){
			if(p[i].same_at <= p[minimum].arrival_time){
				return i;														//ex: if multiple processes have 0 AT, then the = condition will be satisfied, and the index of first process in the iteration will be returned
			}
		}
		return index;
	}
	else if(choice == 1){
		int minimum = p[0].burst_cycle;
		for(i=0; i<total; i++){
			if(minimum>p[i].burst_cycle){
				minimum = p[i].burst_cycle;
				index = i;
			}
			for(j=i; j<total-1; j++){
				if(p[i].burst_cycle == p[j].burst_cycle){
					p[i].same_bc = p[i].burst_cycle;							//Setting same_bc as burst cycle, to identify multiple processes with same BC
					p[j].same_bc = p[i].burst_cycle;
				}
			}
		}
		for(i=original_index; i<total; i++){
			if(p[i].same_bc <= p[minimum].burst_cycle){
				return i;														//ex: if multiple processes have 0 AT, then the = condition will be satisfied, and the index of first process in the iteration will be returned
			}
		}
		return index;
	}
	else if(choice == 2){
		int minimum = p[0].priority;
		for(i=0; i<total; i++){
			if(minimum>p[i].priority){
				minimum = p[i].priority;
				index = i;
			}
		}
		return index;
	}
}

void input_pdata(process_data p){
	printf("Enter the arrival time of this process: ");
	scanf("%d", &(p.arrival_time));
	printf("Enter the burst cycle of this process: ");
	scanf("%d", &(p.burst_cycle));
}

void fcfs(process_data p[]){												//Assuming no processes have same arrival time
	int i, size, current_time=0, minimum_at;								//minimum_at = shortest arrival time
	size = sizeof(p)/sizeof(p[0]);
	for(i=0; i<size; i++){
		minimum_at = min(p, 0, i);											//choice = 0 to compare arrival time
		p[minimum_at].waiting_time = p[minimum_at].arrival_time - current_time;
		p[minimum_at].turn_around_time = p[minimum_at].waiting_time + p[minimum_at].burst_cycle;
		current_time += p[minimum_at].burst_cycle;
	}
}
/*
void sjfs(process_data p[]){														//Non preemptive
	int i, size, current_time = 0, minimum_bc, minimum_at;							//minimum_bc = shortest bus cycle
	size = sizeof(p)/sizeof(p[0]);
	for(i=0; i<size; i++){
		minimum_at = min(p, 0, i);
		minimum_bc = min(p, 1, i);
		if(p[minimum_at].arrival_time >= current_time){
			
		}
		p[minimum_bc].waiting_time = 
	}
}
*/