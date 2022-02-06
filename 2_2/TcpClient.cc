#include"TcpClient.hpp"
#include<cstdlib>
using namespace std;
int main(int argc,char* argv[])
{
  if(argc != 3)
    exit(1);
  TcpClient* client = new TcpClient(argv[1],atoi(argv[2]));
  client->Init();
  client->start();
  delete client;
  return 0;
}
