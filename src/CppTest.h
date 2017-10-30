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
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

void socketClientTest();
void socketServerTest();
#endif /* CPPSOCKET_H_ */
