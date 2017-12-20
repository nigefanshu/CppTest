/*
 * soapmain.cpp
 *
 *  Created on: 2017年12月18日
 *      Author: root
 */
#include <iostream>
#include "soapaddService.h"
#include "add.nsmap"

using namespace std;

//测试soap接口  注意命名空间
int addService::add(int a,int b,int* result){
	*result=a+b;
	return 0;
}

int main(int argc,char** argv){

	if(argc<2)
		return -1;
	cout<<"soap server started:"<<endl;
	addService s;
	s.run(atoi(argv[1])); //插入端口参数
	return 0;
}

