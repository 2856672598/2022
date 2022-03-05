#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
using std::cerr;
using std::endl;
class Sock
{
    public:
        static int Socket()
        {
            int fd = socket(AF_INET,SOCK_STREAM,0);
            if(fd < 0)
            {
                cerr << "socket error"<< endl;
                exit(1);
            }
            return fd;
        }
        static void Bind(int sockfd ,int port)
        {
            struct sockaddr_in local;
            local.sin_family = AF_INET;
            local.sin_port = htons(port);
            local.sin_addr.s_addr = INADDR_ANY;
            if(bind(sockfd,(struct sockaddr*)&local,sizeof(local)) == -1)
            {
               cerr << "bind error"<< endl;
               exit(2);
            }
        }

        static void Listen(int sockfd)
        {
            if(listen(sockfd,10) < 0)
            {
                cerr << "listen error" << endl;
                exit(3);
            }
        }
        static int Accept(int lsockfd)
        {
            struct sockaddr_in remote;
            socklen_t sz = sizeof(remote);
            int fd =accept(lsockfd,(struct sockaddr*)&remote,&sz);
            if(fd < 0)
            {
                cerr << "accept errno" << endl;
                exit(4);
            }
            return fd;
        }
};
