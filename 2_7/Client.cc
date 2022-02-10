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
  Client* client = new Client(argv[1],atoi(argv[2]));
  client->Init();
  client->Start();
  delete client;
  return 0;
}
