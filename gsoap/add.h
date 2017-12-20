


//gsoap ns service name: add
//gsoap ns service namespace: http://localhost/add.wsdl
//gsoap ns service location: http://localhost
//gsoap ns service executable: add.cgi
//gsoap ns service encoding: encoded
//gsoap ns schema namespace: urn:add

//上述几行注释只能修改不能删除
//函数前的ns 是xml命名空间标记，不能删  要么设为函数指针，要么最后一个参数是为指针 or 引用

int ns__add(int a,int b,int* result);

