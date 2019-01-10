#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<string.h>
#include <arpa/inet.h>
#define IP "192.168.175.133"  
#define SPORT  10086
int main()
{
	//定义变量
	int socketID = 0;
	int ret1 = 0;
	int ret2 = 0;
	struct sockaddr_in serverAddr;
	int addrLength = sizeof(struct sockaddr_in);
	char buf[][5] = {
		{0xff,0x00,0x01,0x00,0xff},
		{0xff,0x00,0x02,0x00,0xff},
		{0xff,0x00,0x03,0x00,0xff},
		{0xff,0x00,0x04,0x00,0xff},
		{0xff,0x00,0x00,0x00,0xff}
	};
	//打开socket
	socketID = socket(AF_INET, SOCK_STREAM, 0);
	if (socketID < 0)
	{
		perror("socket error");
		return -1;
	}
	//设置服务器的ip&&port
	memset(&serverAddr, 0, addrLength);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(SPORT);
	serverAddr.sin_addr.s_addr = inet_addr(IP);
	//3、connect() 与服务器建立连接
	 ret1 = connect(socketID,(struct sockaddr*)&serverAddr , addrLength);
	 if(ret1 < 0){
		 perror("connect err4");
		 printf("1");
	//	 close(socketID);
	 }
	 //发送数据
	 //gets(buf);
	 //ret2 = write(socketID,buf,sizeof buf);
	 while(1){
		char ch = getchar();
		switch (ch){
		case 'w':
			send(socketID,buf[0],sizeof buf[0],0);
			memset(buf,0,strlen(buf[0]));
			break;
		case 's':
            send(socketID,buf[1],sizeof buf[1],0);
			memset(buf,0,strlen(buf[1]));
			break;
		case 'a':
		    send(socketID,buf[2],sizeof buf[2],0);
			memset(buf,0,strlen(buf[2]));
			break;
		case'd':
			send(socketID,buf[3],sizeof buf[3],0);
			memset(buf,0,strlen(buf[3]));
			break;
		case ' ':
			send(socketID,buf[4],sizeof buf[4],0);
			memset(buf,0,strlen(buf[0]));
			break;
		}
		 
		 //write(socketid,buf,sizeof buf);
		 //memset(buf,0,strlen(buf));
	 }
	if (ret2 > 0)
	{
		printf("send msg success!\r\n");
	}
	//关闭socket
	close(socketID);
	return 0;
}
	 
