#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

int main(int argc,char*args[]) {

        sockaddr_in s_in;
	int port=8787;
	char buf[100];
	char *sip = "127.0.0.1";
	char *str = "ploikjuyh";

	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(port);
	inet_pton(AF_INET,sip,(void *)&s_in.sin_addr);//点分十进制转二进制用于传输
	int s_fd = socket(AF_INET,SOCK_STREAM,0);

	connect(s_fd,(sockaddr *)&s_in,sizeof(s_in));//根据s_in连接server
	cout<<endl<<str;
	write(s_fd,str,strlen(str)+1);
	read(s_fd,buf,5);
	cout<<endl<<"accept return:"<<buf<<endl;
	close(s_fd);
	return 0;
}
