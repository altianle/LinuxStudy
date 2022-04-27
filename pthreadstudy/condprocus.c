#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

//公共区域item
struct item{
	struct item* next;
	int val;
};

struct item* head;
void* product(void* arg){
	struct item* m;

	while(1){
	    m = malloc(sizeof(struct item));
		m->val = rand() % 1000 + 1;

		pthread_mutex_lock(&mutex);
		m->next = head;
		head = m;
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);

		printf("======I am %lu , i product %d\n",pthread_self(), m->val);
		sleep(rand()%5);
	}
	return;
}

void* cusumer(void* arg){
	struct item* m;

	while(1){
		
		pthread_mutex_lock(&mutex);
		if(head == NULL)
			pthread_cond_wait(&cond, &mutex);
		m = head;
		head = head->next;
		pthread_mutex_unlock(&mutex);

		printf("--------I am %lu , i eat item : %d\n",pthread_self(), m->val);
		free(m);
		sleep(rand()%5);
	}
	return;
}



void main(){
	srand(time(NULL));
	pthread_t pro,cus;
	int ret = pthread_create(&pro, NULL, product, NULL);
	if (ret == -1){
		fprintf(stderr, "pthread create product error:", strerror(ret));
		exit(1);
	}
	ret = pthread_create(&cus, NULL, cusumer, NULL);
	if (ret == -1){
		fprintf(stderr, "pthread create cusumer error:", strerror(ret));
		exit(1);
	}

	pthread_join(pro, NULL);
	pthread_join(cus, NULL);

	return;
}
