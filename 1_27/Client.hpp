#pragma once 

#include<iostream>
#include<string>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<cstdlib>
class Client
{
  public:
    Client(std::string ip = "127.0.0.1",int port = 8080)
      :_ip(ip)
       ,_port(port)
    {}


    void InitClient()
    {
      //创建一个套接字
      sockfd = socket(AF_INET,SOCK_DGRAM,0);
      std::cout<<_ip<<std::endl;
    }

    void Start()
     {
       std::string arr;
      while(true)
      {
        //发送数
        arr.resize(0);
        std::cin>>arr;
        struct sockaddr_in remote;
        remote.sin_family = AF_INET;
        remote.sin_port =htons(_port);
        remote.sin_addr.s_addr =inet_addr(_ip.c_str());
        sendto(sockfd,arr.c_str(),arr.size(),0,(struct sockaddr*)&remote,sizeof(remote));
        socklen_t len = sizeof(remote);
        char buff[128];
        ssize_t s = recvfrom(sockfd,buff,sizeof(buff)-1,0,(struct sockaddr*)&remote,&len);
        if(s>0)
        {
          buff[s]='\0';
          std::cout<<buff<<std::endl;
        }
      }
    }

  private:
    std::string _ip;
    int _port;
    int sockfd;
};
