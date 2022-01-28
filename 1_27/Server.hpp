#pragma once 

#include<iostream>
#include<string>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
class Server
{
  public:
    Server(int port = 8081)
      :_port(port)
    {}


    void InitServer()
    {
      //创建一个套接字
      sockfd = socket(AF_INET,SOCK_DGRAM,0);
      struct sockaddr_in tmp;

      tmp.sin_family = AF_INET;
      tmp.sin_addr.s_addr =INADDR_ANY;
      tmp.sin_port =htons( _port);

      if(bind(sockfd,(sockaddr*)&tmp,sizeof(tmp))== -1)
      {
        std::cerr<<"bind error"<<std::endl;
        exit(1);
      }
      std::cout<< sockfd<<std::endl;
    }

    void Start()
    {
      while(true)
      {

        char arr[128];
        struct sockaddr_in tmp;
        socklen_t len = sizeof(sockaddr_in);
        ssize_t size = recvfrom(sockfd,&arr,sizeof(arr)-1,0,(struct sockaddr*)&tmp,&len);
        if(size>0)
        {
          arr[size]='\0';
          std::cout<< inet_ntoa(tmp.sin_addr)<<":"<<ntohs(tmp.sin_port)<<"#";
          std::cout<<arr<<std::endl;
        }
      }
    }

  private:
    std::string _ip;
    int _port;
    int sockfd;
};
