#pragma once 

#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<cstdlib>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>
#include"ThreadPoll.hpp"
#define BACKLOG 10
class TcpServer
{
  public:
    TcpServer(int port = 8080)
      :_port(port)
       ,p(NULL)
    {}

    ~TcpServer()
    {
      delete p;
    }

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
      p = new ThreadPool<Task>(2);
      std::cout<<p<<std::endl;
      p->Init();
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
        Task* tmp = new Task(fd);
        p->Push(tmp);
      }
    }
  private:
    int _port;
    int _sockfd;
    ThreadPool<Task>* p;
};
