#include<stdio.h>
#include<unistd.h>
int main() {
	int pipefd[2];
	int returnstat;
	char s1[20] = "OS pipe";
	char s2[20] = "Program";
	char r1[20], r2[20];
	returnstat = pipe(pipefd);
	if(returnstat == -1) {
		printf("unable to create the file");
	}
	write(pipefd[1], s1, sizeof(s1));
	read(pipefd[0], r1, sizeof(s1));
	printf("%s ", r1);
	write(pipefd[1], s2, sizeof(s2));
	read(pipefd[0], r2, sizeof(s2));
	printf("%s", r2);
	return 0;
}
