#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
int main()
{
	printf("before fork\n");
	printf("==================\n");
	pid_t pid = fork();
	if (pid==-1){
		perror("fork error\n!");
		exit(1);
	}
	else if(pid==0){
		printf("I am child fork,my fork id is :%d\n",getpid());
		printf("my parent folk id is:%d\n",getppid());
	}
	else if(pid>0){
		printf("My child fork is:%d\n",pid);
	}
	printf("====time-to-end====\n");

	return 0;



}
