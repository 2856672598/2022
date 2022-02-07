#pragma once 

#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/wait.h>
#include<unistd.h>
#include<cstdlib>
#include"Protocol.hpp"
#define BACKLOG 5

class Server
{
  public:
    Server(int port)
      :_port(port)
    {
    }

    void Init()
    {
      sockfd = socket(AF_INET,SOCK_STREAM,0);
      if(sockfd == -1)
      {
        std::cerr<<"socket errno"<<std::endl;
        exit(1);
      }
      struct sockaddr_in local;
      local.sin_family = AF_INET;
      local.sin_port = htons(_port);
      local.sin_addr.s_addr = INADDR_ANY;
      if(bind(sockfd,(struct sockaddr*)&local,sizeof(local)) == -1)
      {
        std::cerr<<"bind errno"<<std::endl;
        exit(2);
      }

      if( listen(sockfd,BACKLOG) == -1)
      {
        std::cerr<<"listen errno"<<std::endl;
        exit(3);
      }

    }

    void Cal(int sock)
    {
      struct Response* ps = new Response;
      struct Request* pq = new Request;

      ssize_t sz = recv(sock,pq,sizeof(Request),0);
      if(sz > 0)
      {
        ps->state = 0;
        switch(pq->op)
        {
          case '+':
            ps->sum = pq->x + pq->y;
            break;
          case '-':
            ps->sum = pq->x - pq->y;
            break;
          case '*':
            ps->sum = pq->x * pq->y;
            break;
          case '/':
            if(pq->y == 0)
            {
              ps->state = 1;
              break;
            }
            ps->sum = pq->x / pq->y;
            break;
          default :
            ps->state = 2;
            break;
        }
        send(sock,ps,sizeof(Response),0);
      }
      close(sock);
    }

    void Start()
    {
      struct sockaddr_in remote;
      socklen_t sz = sizeof(sockaddr_in);
      while(1)
      {
        int sk = accept(sockfd,(sockaddr*)&remote,&sz);
        if(sk >= 0)
        {
          if(fork() == 0)
          {
            if(fork() != 0)
              exit(1);
            Cal(sk);

            close(sockfd);
          }
          waitpid(-1,NULL,0);
          close(sk);
        }
      }
    }

    ~Server()
    {
      close(sockfd);
    }
  private:
    int _port;
    int sockfd;
};
