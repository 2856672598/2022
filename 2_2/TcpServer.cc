#include"TcpServer.hpp"

using namespace std;

int main()
{
  TcpServer* tcp = new TcpServer;
  tcp->Init();
  tcp->start();

  delete tcp;
  return 0;

}
