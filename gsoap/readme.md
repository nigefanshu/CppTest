#编码和编译
首先声明客户端和服务端的通信接口函数  cat add.h:

//gsoap ns service name: add
//gsoap ns service namespace: http://localhost/add.wsdl
//gsoap ns service location: http://localhost
//gsoap ns service executable: add.cgi
//gsoap ns service encoding: encoded
//gsoap ns schema namespace: urn:add
//上述几行注释只能修改不能删除
//函数前的ns 是xml命名空间标记，不能删  要么设为函数指针，要么最后一个参数是为指针 or 引用

int ns__add(int a,int b,int* result);

###接着使用soapcpp2 -i -c++11 add.h 命令自动生成服务端service、客户端proxy等类工具（含xml与c++数据转换）

编写myserver.cpp 定义上面声明过的接口函数，并通过service在main函数
编写myclient.cpp 通过proxy在main函数内调用通信接口

使用通用的makefile 进行make构建