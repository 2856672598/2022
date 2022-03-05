#include "Sock.hpp"

#include <unistd.h>
#include <sys/select.h>
#define SIZE (sizeof(fd_set)*8)
#define INITVAL -1

using namespace std;
class Server
{
    private:
        int _port;
        int _lsockfd;//监听套接字
        int readarr[SIZE];
    public:
        Server(int port = 8080)
            :_port(port)
        {}

        void Init()
        {
            int opt = 1;
            for(int i = 0;i < (int)SIZE ;i++)
            {
                readarr[i] = INITVAL;
            }
            _lsockfd = Sock::Socket();
            setsockopt(_lsockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
            Sock::Bind(_lsockfd,_port);
            Sock::Listen(_lsockfd);
            readarr[0] = 3;
            cout<<"初始化完成"<<_lsockfd<<endl;
        }
        void Addset(int fd)
        {
            int i = 0;
            for(;i < (int)SIZE;i++)
            {
                if(readarr[i] == INITVAL)
                    break;
            }
            if(i < (int)SIZE)
            {
                readarr[i] = fd;
            }
            else 
                cerr <<"readarr full" <<endl;
        }

        void ClearSet(int fd)
        {
            for(int i = 0;i < (int)SIZE;i++)
            {
                if(readarr[i] == fd)
                {
                    readarr[i] =INITVAL;
                    break;
                }
            }
        }

        void Start()
        {
            int maxfd;
            fd_set readfds;
            while(true)
            {
                maxfd = 0;
                FD_ZERO(&readfds);
                for(int i = 0;i < (int)SIZE;i++)
                {
                    if(readarr[i] != INITVAL)
                    {
                        FD_SET(readarr[i],&readfds);
                        if(readarr[i] > maxfd)
                            maxfd = readarr[i];
                    }
                }
                timeval timeout{1,0};
                int start = select(maxfd + 1,&readfds,nullptr,nullptr,&timeout);
                if(start > 0)
                {
                    for(int i = 0;i <= maxfd;i++)
                    {
                        if(FD_ISSET(i,&readfds))
                        {
                            if(i == _lsockfd)
                            {
                                //连接已就绪
                                int fd = Sock::Accept(_lsockfd);
                                Addset(fd);
                            }
                            else 
                            {
                                char buff[1024];
                                ssize_t sz = read(i,&buff,sizeof(buff)-1);
                                if(sz == 0)
                                {
                                    cout<<"remote close"<<endl;
                                    ClearSet(i);
                                }
                                else 
                                {
                                    buff[sz] = 0;
                                    printf("%s\n",buff);
                                }
                            }
                        }
                    }
                }
            }
        }
};
