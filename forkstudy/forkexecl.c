#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

int main(int argc,char *argv[]){
	pid_t pid = fork();
	if (pid==-1){
		perror("creat child fork fail\n");
		exit(1);
	}
	else if(pid==0){
		//execlp("ls","-l","-h",NULL);//错误写法，ls后跟着的是argv[0]
		//execlp("ls","ls","-l","-h",NULL);
		execl("../makefilestudy/source/a.out","a.out",NULL);
		perror("exec error");
		exit(1);
	}
	else if(pid>0){
		printf("I am parent:%d\n",getpid());
		sleep(1);
	}
	return 0;
}
