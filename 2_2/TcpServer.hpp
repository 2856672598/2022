#pragma once 

#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<cstdlib>
#include<unistd.h>
#include<signal.h>
#define BACKLOG 10
class TcpServer
{
  public:
    TcpServer(int port = 8080)
      :_port(port)
    {}

    void Init()
    {
      signal(SIGCHLD,SIG_IGN);
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

    void service(int sockfd)
    {
      char buff[128];
      while(true)
      {
        ssize_t sz = recv(sockfd,buff,sizeof(buff)-1,0);
        if(sz > 0)
        {
          buff[sz] = '\0';
          std::cout<<buff<<std::endl;
          send(sockfd,buff,sz,0);
        }
        else if(sz == -1)
        {
          std::cerr<<"recv errno"<<std::endl;
          exit(1);
        }
        else 
        {
          std::cout<<"断开连接"<<std::endl;
          break;
        }
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
        std::cout<<"["<<inet_ntoa(endpoint.sin_addr)<<"]连接成功"<<std::endl;
        //创建子进程
        if(fork() == 0)
        {
          service(fd);
          close(_sockfd);
          exit(0);
        }
        close(fd);
      }

    }
  private:
    int _port;
    int _sockfd;
};
