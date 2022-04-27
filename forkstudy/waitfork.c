#include"stdlib.h"
#include"stdio.h"
#include"unistd.h"
#include"pthread.h"
#include<sys/wait.h>

int main(int argc,char *argv[]){
	pid_t pid,wpid;
	int status;
	pid=fork();
	if(pid==-1){
		perror("child fork error");
		exit(1);
	}else if(pid==0){
		printf("I am child,my ID is:%d,my parent is:%d \n",getpid(),getppid());
		sleep(10);
		printf("child dying\n");
		return 8;
	}else if(pid>0){
		printf("I am parent fork,my ID is %d\n",getpid());
		wpid=wait(&status);//如果子进程不死亡，父进程会阻塞在此
		if(wpid==-1){
			perror("wait error");
		}
		if(WIFEXITED(status)){   //若为真，说明子进程正常终止
			printf("chile exit with %d\n",WEXITSTATUS(status));
		}
		if(WIFSIGNALED(status)){//若为真，说明子进程被信号终止
			printf("child kill with signal %d\n",WTERMSIG(status));
		}
	}
	return 0;
}
