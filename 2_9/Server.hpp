#pragma once 
#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<cstdlib>
#include<unistd.h>
#include<signal.h>
#include<string>

#define BACKLOG 5
class Server
{
  public:
    Server(int port = 8080)
      :_port(port)
       ,_sockfd(-1)
    {}

    ~Server()
    {
      close(_sockfd);
    }

    void Init()
    {
      signal(SIGCHLD,SIG_IGN);
      _sockfd = socket(AF_INET,SOCK_STREAM,0);
      if(_sockfd < 0)
      {
        std::cerr<<"socket errno"<<std::endl;
        exit(1);
      }
      struct sockaddr_in local;
      local.sin_family = AF_INET;
      local.sin_port = htons(_port);
      local.sin_addr.s_addr = INADDR_ANY;

      if(bind(_sockfd,(struct sockaddr*)&local,sizeof(local)) < 0 )
      {
        std::cerr<<"bind errno"<<std::endl;
        exit(2);
      }

      if(listen(_sockfd,BACKLOG) == -1)
      {
        std::cerr<<"listen errno"<<std::endl;
      }
    }
    
    void Task(int sock)
    {
      char buff[2048];
      ssize_t sz = recv(sock,buff,sizeof(buff)-1,0);
      if(sz > 0)
      {
        std::cout<<buff<<std::endl;
        std::string response;
        response += "HTTP/1.0 200 OK \r\n";
        response += "Conten : text/html\r\n";
        response += "\r\n";

        response += "\
          <html>\
            <head>\
              <title>welcome</title>\
            </head>\
            <body>\
              <h1>hello</h1>\
              <p>Hello</p>\
            </body>\
          </html>\r\n";
        send(sock,response.c_str(),response.size(),0);
      }
      close(sock);
    }

    void Start()
    {
      struct sockaddr_in remote;
      socklen_t addrlen = sizeof(remote);
      while(true)
      {
        int sock = accept(_sockfd,(struct sockaddr*)&remote,&addrlen);
        if(sock > 0)
        {
          if(fork() == 0)
          {
            close(_sockfd);
            Task(sock);
            exit(3);
          }
          close(sock);
        }
      }
    }

  private:
    int _port;
    int _sockfd;
};
