#include"Client.hpp"

int main(int argc,char* argv[])
{
  std::cout<<argv[1]<<" "<<argv[2]<<std::endl;
  if(argc != 3)
    exit(1);
  Client* client = new Client(argv[1],atoi(argv[2]));
  client->InitClient();
  client->Start();
  return 0;
}
