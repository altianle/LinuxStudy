#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>
#include<strings.h>
#include<fcntl.h>
#include<ctype.h>
#include<arpa/inet.h>
#include<stdio.h>

#define SERPORT 6666

int main(){
    int lfd, cfd, n;
    struct sockaddr_in ser,clien;
    socklen_t clienlen;
    char buf[1024], cliip[BUFSIZ];

    lfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&ser, sizeof(ser));//清空结构体
    ser.sin_family = AF_INET;
    ser.sin_port = htons(SERPORT);
    ser.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(lfd, (struct sockaddr*)&ser, sizeof(ser));
    listen(lfd, 1024);

    clienlen = sizeof(clien);
    cfd = accept(lfd, (struct sockaddr*)&clien, &clienlen);

    //打印连接客户端
    inet_ntop(AF_INET, &clien.sin_addr.s_addr, cliip, sizeof(cliip));//客户端IP地址
    printf("客户端的IP地址为：%s ,端口号为： %d\n", cliip, ntohs(clien.sin_port));

    while(1){
        n = read(cfd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, n);
        for(int i = 0; i < n; i++)
            buf[i] = toupper(buf[i]);

        write(cfd, buf, n);
    }
    close(lfd);
    close(cfd);
    return 0;
}