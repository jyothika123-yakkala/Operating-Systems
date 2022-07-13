#include<stdio.h>
int main() {
	int a[100], i, wt, tat, n, min, j;
	float sum = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - 1 - i; j++){
			if(a[j] > a[j + 1]) {
				min = a[j];
				a[j] = a[j + 1];
				a[j + 1] = min;
			}
		}
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
