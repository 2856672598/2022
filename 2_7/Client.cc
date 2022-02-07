#include"Client.hpp"
#include<string>
void Manual(std::string name)
{
  std::cout<<"name ip post"<<std::endl;
}
int main(int argc,char* argv[])
{
  if(argc != 3)
  {
    Manual(argv[0]);
    exit(1);
  }
  Client* client = new Client("127.0.0.1",8080);
  client->Init();
  client->Start();
  delete client;
  return 0;
}
