#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

void sys_err(const char* str){
	perror(str);
	exit(1);
}

int main(int argc,char *argv[]){
	int fd[2];
	int ret;
	char buf[1024];
	ret = pipe(fd);
	if(ret==-1){
		sys_err("pipe error");
	}
	pid_t pid = fork();
	if(pid>0){//父进程
		close(fd[0]);
		write(fd[1],"hello pipe\n",strlen("hello pipe\n"));
		close(fd[1]);
	}else if(pid==0){//子进程
		close(fd[1]);
		int ret = read(fd[0],buf,sizeof(buf));//返回实际读到的字节数
		write(STDOUT_FILENO,buf,ret);
		close(fd[0]);
	}
	return 0;
}
