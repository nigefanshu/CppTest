#include <iostream>
#include "soapaddProxy.h"
#include "add.nsmap"

using namespace std;

int main(int argc, char* argv[]){

	addProxy p;//客户端代理，帮助导向服务端
	p.soap_endpoint=argv[1];//插入ip地址 端口参数
	int sum =0;
	p.add(1,1,&sum);
	cout<<"sum: "<<sum<<endl;
}
