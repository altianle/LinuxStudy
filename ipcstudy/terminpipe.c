#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<string.h>
int main(int argc,char *argv[]){
	pid_t pid;
	int ret,readnu,writenu;
	int fd[2];
	char buf[1024];
	ret = pipe(fd);
	if(ret == -1){
		perror("pip error");
		exit(1);
	}

	pid = fork();
	if(pid == -1){
		perror("fork error");
	}else if(pid == 0){//子进程
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("wc","wc","-l",NULL);
	}else if(pid > 0){//父进程
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execlp("ls","ls",NULL);
	}
	return 0;
}

