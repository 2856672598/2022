#pragma once
#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<cstdlib>
#include<arpa/inet.h>
#include<string>
#include<unistd.h>
#include"Protocol.hpp"
class Client
{
  public:
    Client(std::string ip ,int port = 8080)
      :_port(port)
       ,_ip(ip)
    {}

    ~Client()
    {
      close(_sockfd);
    }

    void Init()
    {
      _sockfd = socket(AF_INET,SOCK_STREAM,0);
      if(_sockfd == -1)
      {
        std::cerr<<"socket errno"<<std::endl;
        exit(1);
      }

      struct sockaddr_in remote;
      remote.sin_family = AF_INET;
      remote.sin_port = htons(_port);
      remote.sin_addr.s_addr = inet_addr(_ip.c_str());
      if( connect(_sockfd,(struct sockaddr*)&remote,sizeof(sockaddr_in)) ==-1)
      {
        std::cerr<<"connect errno"<<std::endl;
        exit(2);
      }
    
    }

    void Start()
    {
      Request* pq = new Request;
      Response* ps = new Response;
      std::cout<<"输入第一个操作数"<<std::endl;
      std::cin>>pq->x;
      std::cout<<"输入第二个操作数"<<std::endl;
      std::cin>>pq->y;
      std::cout<<"输入操作符（+、-、*、/)"<<std::endl;
      std::cin>>pq->op;
      send(_sockfd,pq,sizeof(Request),0);
      recv(_sockfd,ps,sizeof(Response),0);
      std::cout<<"sum = "<<ps->sum<<std::endl;
      std::cout<<"state :"<<ps->state<<std::endl;
      delete pq;
      delete ps;
    }
  private:
    int _port;
    std::string _ip;
    int _sockfd;
};
