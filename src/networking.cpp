/*
 * networking.cpp
 *
 *  Created on: 2017年10月26日
 *      Author: root
 */
#include "CppTest.h"

using namespace std;

void socketServerTest(){

    /*网络套接字地址结构体 服务端servaddr 客户端cliaddr*/
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    char buf[80];
    char str[INET_ADDRSTRLEN];//#define INET_ADDRSTRLEN 16  /* for IPv4 dotted-decimal */
    int i, n;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);  //打开一个socket，分配一个文件描述符listenfd

//    bzero(&servaddr, sizeof(servaddr));          //清空服务端套接字  可选
    servaddr.sin_family = AF_INET;               //地址采用IPv4地址
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//地址从主机字节顺序转换成网络字节顺序
    servaddr.sin_port = htons(8787);        //端口号从主机字节顺序转换成网络字节顺序

    bind(listenfd, (sockaddr*)&servaddr, sizeof(servaddr));//socket 绑定端口等参数
    listen(listenfd, 20);//开始监听，最大20条线

    printf("等待连接中...\n");
    while(1){
        cliaddr_len = sizeof(cliaddr);//sizeof得出的unsigned int还要另外强转成 socket_t,typedef int socket_t

        connfd = accept(listenfd, (sockaddr*)&cliaddr, &cliaddr_len);//除了监听的fd再新建一个连接的fd

        n = read(connfd, buf, 80);
        printf("received from %s at PORT %d\n",
                inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),//地址二进制转点分十进制
                ntohs(cliaddr.sin_port));

        for(i = 0; i<n; i++){
            buf[i] = toupper(buf[i]);
        }
        /*往connfd中写数据*/
        write(connfd, buf, n);
        close(connfd);
    }
    close(listenfd);
}

void socketClientTest(){

    struct sockaddr_in servaddr;
    char buf[80];
    int sockfd, n;
    char *contentstr;

    contentstr = "clientsendto..";
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

//    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "192.168.2.138", &servaddr.sin_addr);//地址点分十进制转二进制，用于传输
    servaddr.sin_port = htons(8787);
    /*连接*/
    connect(sockfd, (sockaddr *)&servaddr, sizeof(servaddr));//为socket绑定参数，连接到服务端
    /*向sockfd写入字符串str*/
    write(sockfd, contentstr, strlen(contentstr));
    /*读取经过服务端处理的sockfd到buf中*/
    n = read(sockfd, buf, 80);
    printf("服务端应答:\n");
    /*输出buf*/

    write(1, buf, n);
    close(sockfd);
}

void domain_to_IPAddr(char* domainName){// <netdb.h>
	hostent *pHE=::gethostbyname(domainName); //host entry 一个包含主机信息的对象
	if(NULL==pHE){cout<<"error  parameter"<<endl;  return;}
	cout<<inet_ntoa(*((in_addr*)pHE->h_addr_list[0]));  //in_addr网络字节序IPV4  转成IPV4字符串格式
}
