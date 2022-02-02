#pragma once 

#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<cstdlib>
#define BACKLOG 10
class TcpServer
{
  public:
    TcpServer(int port = 8080)
      :_port(port)
    {
      _sockfd = socket(AF_INET,SOCK_STREAM,0);
      struct sockaddr_in local;
      local.sin_family = AF_INET;
      local.sin_port = htons(_port);
      local.sin_addr.s_addr = INADDR_ANY;
      if(bind(_sockfd,(struct sockaddr*)&local,sizeof(sockaddr_in)) < 0)
      {
        std::cerr<<"bind error"<<std::endl;
        exit(1);
      }

      if(listen(_sockfd,BACKLOG)< 0 )
      {
        std::cout<<"bind error"<<std::endl;
        exit(1);
      }
    }
    
    void start()
    {
      struct sockaddr_in endpoint;
      socklen_t sz = sizeof(endpoint);

      while(true)
      {
        int fd = accept(_sockfd,(sockaddr*)&endpoint,&sz);
        if(fd < 0)
          continue;

        char buff[128];
        ssize_t size = recv(fd,buff,sizeof(buff)-1,0);
        std::cout<<"链接成功"<<std::endl;
        if(size > 0)
        {
          buff[size] = '\0';
          std::cout<<buff<<std::endl;
        }
      }

    }
  private:
    int _port;
    int _sockfd;
};
