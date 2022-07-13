#include<stdio.h>
#include<unistd.h>
int main() {
	int pipestd[2], pipestd1[2];
	int returnstat, returnstat1;
	char s1[20] = "Two pipes";
	char s2[20] = "Progarm in os";
	char r1[20];
	returnstat = pipe(pipestd);
	returnstat1 = pipe(pipestd1);
	if(returnstat == -1){
		printf("unable to create pipe1");
	}
	if(returnstat1 == -1){
		printf("unable to create pipe2");
	}
	int pid = fork();
	if(pid != 0){
		close(pipestd[0]);
		close(pipestd1[1]);
		write(pipestd[1], s1, sizeof(s1));
		read(pipestd1[0], r1, sizeof(r1));
		printf("%s ", r1);
	}
	else {
		close(pipestd[1]);
		close(pipestd1[0]);
		read(pipestd[0], r1, sizeof(r1));
		write(pipestd1[1], s2, sizeof(s2));
		printf("%s", r1);
	}
	return 0;
}
