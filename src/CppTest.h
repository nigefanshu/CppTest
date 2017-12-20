/*
 * CppTest.h
 *
 *  Created on: 2017年10月25日
 *      Author: root
 */
//通用的头文件、全局变量聚集地
#ifndef CPPSOCKET_H_
#define CPPSOCKET_H_

#include <string.h>
#include <iostream>//cout
#include <sys/socket.h>//socket方法
#include <netinet/in.h>//网络连接输入输出 sockaddr_in
#include <arpa/inet.h>//网络连接参数转换inet_ntop等  in_addr
#include <unistd.h>//unix方法 sleep等
#include <cstdio>//read  write
#include <netdb.h>//hostent(:host entry)  gethostbyname(char*)
#include <thread>

//socket通信基础  多线程
void socketClientTest();
void socketServerTest();

//域名转IP地址
void domain_to_IPAddr(char* domainName);

#endif /* CPPSOCKET_H_ */
