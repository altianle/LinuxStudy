#include<stdio.h>
#include<unistd.h>

void main(){
	int i;
	alarm(1);
	for(i=0;;i++){
		printf("%d\n",i);
	}
}
