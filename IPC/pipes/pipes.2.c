#include<stdio.h>
#include<unistd.h>
int main() {
	int pipestd[2];
	int returnstat;
	char s1[20] = "parent child";
	char s2[20] = "pipe program";
	char r1[20];
	returnstat = pipe(pipestd);
	if(returnstat == -1) {
		printf("unable to create a pipe");
	}
	int pid = fork();
	if(pid == 0){
		read(pipestd[0], r1, sizeof(r1));
		printf("%s ", r1);
		read(pipestd[0], r1, sizeof(r1));
		printf("%s ", r1);
	}
	else {
		write(pipestd[1], s1, sizeof(s1));
		write(pipestd[1], s2, sizeof(s2));
	}
	return 0;
}
