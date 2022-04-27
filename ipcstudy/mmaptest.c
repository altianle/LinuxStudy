#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/mman.h>
#include<unistd.h>

void sys_error(const char* str){
	perror(str);
	exit(1);
}

int main(int argc, char* argv[]){
	char *p = NULL;
	int fd = open("mmaptxt", O_RDWR|O_CREAT|O_TRUNC,0600);
	if(fd == -1){
		sys_error("open error");
	}
/*
	lseek(fd, 10, SEEK_END);
	write(fd,"\0",1);
*/	
	ftruncate(fd,20);//与上面2行代码等价
	int len = lseek(fd, 0, SEEK_END);
	p = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(p == MAP_FAILED){
		sys_error("mmap error");
	}
	strcpy(p, "hello mmap");//使用指针对文件进行写操作
	printf("-----%s\n",p);

	int ret = munmap(p, len);
	if(ret == -1){
		sys_error("munmap error");
	}
	return 0;
}
