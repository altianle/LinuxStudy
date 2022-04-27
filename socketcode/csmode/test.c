#include<stdio.h>  
void fun(int *p)  
{  
    *p=22;  
}  
int main(void)  
{  
    int a=1;  
    int *q;  
    q=&a;  
    printf("%d\n",*q);  
    fun(*q);  
    printf("%d\n",*q);  
    return 0;  
} 
