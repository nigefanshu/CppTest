//============================================================================
// Name        : CppTest.cpp
// Author      : joe
// Version     :
// Copyright   : all  rights  reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "CppTest.h"

//单元测试框架catch2 必须声明在头文件前
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

TEST_CASE("测试标签字符串"){
	//使用REQUIRE系列函数调用测试函数
//	REQUIRE(add(1,1)==2);
}

using namespace std;

int main(int argc,char*args[]) {

	//单元测试catch2
	Catch::Session().run(argc,args);

	//测试socket编程
//	if(argc>1){
//		cout<<"arg:"<<args[1]<<"  server"<<endl;
//		socketServerTest();
//	}
//	else{
//		cout<<"client"<<endl;
//		socketClientTest();
//	}

	//多线程文件传输
//	if(argc>1){
//		cout<<"arg:"<<args[1]<<" server"<<endl;
//
//	}
//	else{
//		cout<<"arg:"<<" client"<<endl;
//
//	}

	//输入域名打印出相应的额ip地址
//	domain_to_IPAddr("www.baidu.com");

	//消息队列测试

	return 0;
}


