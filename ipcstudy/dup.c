#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
	int oldf=open(argv[1],O_WRONLY);
//	int newf=dup(oldf);
//	printf("new file is:%d\n",newf);
	write(oldf,"1234567",7);
	return 0;
}
