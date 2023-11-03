#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
/*
struct sockaddr_in
{
    sa_family_t     sin_family; //地址类型
    uint16_t        sin_port;   //端口号（16位）
    struct in_addr  sin_addr;
    char            sin_zero[8];

};
*/


int main()
{
    // AF_INET 指的是 ipv4 ， 类似的 AF_INET6 就是 ipv6
    // SOCK_STREAM 可靠连接（一般TCP），相对的是SOCK_DGRAM（UDP）
    /** protocol: Protocol value for Internet Protocol(IP), which is 0. 
    /* This is the same number which appears on protocol field in the IP header of a packet.
    /* (man protocols for more details)
    */
    int serv_sock = socket(AF_INET, SOCK_STREAM, 0); 
    // create a socket
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(1234);  //端口
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    
    // 进入监听
    listen(serv_sock, 20);

    // 接受请求
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

    // 解析请求


    // 发送数据
    char str[] = "Hello World!";
    write(clnt_sock, str, sizeof(str));

    // 关闭Socket
    close(clnt_sock);
    close(serv_sock);

    return 0;    
}   

// 以上的代码是均可以正常运行的