#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>
#include<fcntl.h>
#include<ctype.h>
#include<arpa/inet.h>
#include<stdio.h>

#define SER_PORT 6666
#define SER_IP "127.0.0.1"

int main(){
    int cfd, n;
    struct sockaddr_in ser_addr;
    char buf[BUFSIZ];

    cfd = socket(AF_INET, SOCK_STREAM, 0);//客户端会自动绑定

    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(SER_PORT);
    inet_pton(AF_INET, SER_IP, &ser_addr.sin_addr.s_addr);

    int ret = connect(cfd, (struct sockaddr*)&ser_addr, sizeof(ser_addr));
    if(ret == 0){
        printf("与服务器端连接成功！\n");
    }else {
        printf("与服务器端连接失败！\n");
    }

    while(1){
        fgets(buf, sizeof(buf), stdin);
        write(cfd, buf, strlen(buf));
        n = read(cfd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, n);
    }
    return 0;
}