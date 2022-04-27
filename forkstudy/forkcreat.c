#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

int main(int argc,char *argv[]){
	int i = 0;
	for(i=0;i<5;i++){
		if(fork()==0)
			break;
	}
	if(i==5){
		sleep(5);
		printf("i am parent\n");
	}
	else{
		sleep(i);
		printf("i am %dth child\n",i+1);
	}
	return 0;
}
