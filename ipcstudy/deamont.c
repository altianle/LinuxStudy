#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

void main(){
	int fd;
	pid_t pid;
	pid = fork();
	if(pid > 0)
		exit(0);
	if(pid == 0){
		setsid();
		fd = open("/dev/null",O_RDWR);
		chdir("/home/alian/Code/");
		umask(0022);
		close(STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
		dup2(fd, STDIN_FILENO);
		while(1);
		return;
	}
}
