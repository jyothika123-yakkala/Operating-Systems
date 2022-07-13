#include<stdio.h>
int main() {
	int a[10], i, n;
	float wt, tat, sum = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	float sum1 = a[0];
	tat = a[0];
	wt = 0;
	for(i = 1; i < n; i++){
		wt = tat;
		sum += wt;
		tat = wt + a[i];
		sum1 += tat;
	}
	printf("The avg waiting time is %f\n", sum / n);
	printf("The avg turn around time is %f\n", sum1 / n);
	return 0;
}
