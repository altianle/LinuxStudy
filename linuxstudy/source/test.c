#include<stdio.h>
#include<stdlib.h>
#include"mymath.h"
int main(){
    int a = 6;
    int b = 4;
    printf("%d + %d = %d\n",a,b,add(a,b));
    printf("%d - %d = %d\n",a,b,sub(a,b));
    return 0;
}

