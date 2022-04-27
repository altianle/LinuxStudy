#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

struct thrd{
	int var;
	char str[128];
};

void *tfn(void* arg){
	struct thrd *test;
	test = malloc(sizeof(test));
	test->var = 100;
	//test->str = "hellow,thread"
	strcpy(test->str,"hellow, thread");
	return (void*)test;
}

void main(){
	pthread_t tid;//线程号
	struct thrd* test; 

	pthread_create(&tid, NULL, tfn, NULL);

	pthread_join(tid, (void**)&test);
	printf("var:%d,str:%s\n",test->var,test->str);
	pthread_exit(NULL);
	//return;
}
