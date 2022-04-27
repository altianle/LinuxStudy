#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

void *tfn(void* arg){
	printf("我是第:%ld个线程，我的线程号是：%lu\n",(long)arg + 1, pthread_self());
	return NULL;
}

void main(){
	pthread_t tid;//线程号
	for(long i = 0; i < 5; i++){
		tid = pthread_self();//tid为long unsign
		int ret = pthread_create(&tid, NULL, tfn, (void *)i);
	}
	printf("我是主线程，我即将GG\n");
	//sleep(5);
	pthread_exit(NULL);
	//return;
}
