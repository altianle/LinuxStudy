#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>
#include<strings.h>
#include<fcntl.h>
#include<ctype.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<sys/wait.h>

#define SER_PORT  6666 

void wait_child(int signo){
    while(waitpid(0, NULL, WNOHANG) > 0);
    return;
}

int main(){
    int cfd, lfd, n, ret;
    pid_t pid;
    struct sockaddr_in ser_addr, cli_addr;
    socklen_t cli_addr_len;
    char buf[BUFSIZ];
    char cli_ip[BUFSIZ];

    lfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&ser_addr, sizeof(ser_addr));

    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(SER_PORT);
    ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(lfd, (struct sockaddr *)&ser_addr, sizeof(ser_addr));
    listen(lfd, 128);

    while(1){
        cli_addr_len = sizeof(cli_addr);
        accept(lfd, (struct sockaddr *)&cli_addr, &cli_addr_len);

        inet_ntop(AF_INET, &cli_addr.sin_addr.s_addr, cli_ip, sizeof(cli_ip));
        printf("连接客户端成功，客户端IP：%s ,端口号：%d\n", cli_ip, ntohs(cli_addr.sin_port));

        pid = fork();
        if(pid == -1){
            perror("fork2 error");
            exit(1);
        } else if(pid == 0){
            break;
        } else if(pid > 0){
            close(cfd);
            signal(SIGCHLD, wait_child);
        }
    }

    if(pid == 0){
        close(lfd);
        while(1){           
            n = read(cfd, buf, sizeof(buf));
            write(STDOUT_FILENO, buf, n);
            for(int i = 0; i < n; i++){
                buf[i] = toupper(buf[i]);
            }
            write(cfd, buf, n);
        }
        close(cfd);

    }
    return 0;
}