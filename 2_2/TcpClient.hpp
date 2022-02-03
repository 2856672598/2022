#include<iostream>
#include<string>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<cstdlib>
#include<unistd.h>
class TcpClient
{
  public:
    TcpClient(std::string ip ,int port)
      :_port(port),_ip(ip)
    {}

    void Init()
    {
      sockfd = socket(AF_INET,SOCK_STREAM,0);
      if(sockfd == -1)
      {
        std::cerr<<"socket errno"<<std::endl;
        exit(1);
      }
      struct sockaddr_in remote;
      remote.sin_family = AF_INET;
      remote.sin_port = htons(_port);
      remote.sin_addr.s_addr = inet_addr(_ip.c_str());
      int flag = connect(sockfd,(struct sockaddr*)&remote,(socklen_t)sizeof(struct sockaddr_in));
      if(flag  == -1)
      {
        std::cerr<<"bind errno"<<std::endl;
        exit(2);
      }
    }

    void start()
    {
      while(true)
      {
        char buff[128];
        ssize_t sz = read(0,buff,sizeof(buff));
        if(sz == 0)
          continue;
        send(sockfd,buff,sz-1,0);
        sz = recv(sockfd,buff,sizeof(buff)-1,0);
        if(sz > 0)
        {
          buff[sz] = '\0';
          std::cout<<"Server echo ："<<buff<<std::endl;
        }
        //else if(sz == 0)
          //break;
        else
        {
          std::cerr<<"recv errn"<<std::endl;
          exit(1);
        }
      }
    }

  private:
    int _port;
    std::string _ip;
    int sockfd;
};
