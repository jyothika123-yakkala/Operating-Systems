#include<stdio.h>
int main() {
	int i, j, n, time, remain, flag = 0, ts;
	int sum_wait = 0, sum_turnaround = 0, at[10], bt[10], rt[10];
	printf("Enter no of processes:");
	scanf("%d", &n);
	remain = n;
	for(i = 0; i < n; i++) {
		printf("Enter the arrival time and burst time p[%d]", i + 1);
		scanf("%d", &at[i]);
		scanf("%d", &bt[i]);
		rt[i] = bt[i];
	}
	printf("Enter the time slice:");
	scanf("%d", &ts);
	printf("\n\nprocess\tArrival time\tturn around time\twaiting time\n\n");
	for(time = 0, i = 0; remain != 0;) {
		if(rt[i] <= ts && rt[i] > 0){
			time += rt[i];
			rt[i] = 0;
			flag = 1;
		}
		else if(rt[i] > 0){
			rt[i] -= ts;
			time += ts;
		}
		if(rt[i] == 0 && flag == 1) {
			remain--;
			printf("p[%d]\t\t%d\t%d\t\t%d\n", i + 1, at[i], time - at[i], time - at[i] - bt[i]);
			sum_wait += time - at[i] - bt[i];
			sum_turnaround += time - at[i];
			flag = 0;
		}
		if(i == n - 1)
			i = 0;
		else if(at[i + 1] <= time)
			i++;
		else
			i = 0;
		}
		printf("The avg sum_wait = %f\n", sum_wait * 1.0/n);
		printf("Avg sum_turn around = %f", sum_turnaround * 1.0/n);
		return 0;
	}
