#include"Server.hpp"

int main()
{
  Server* server = new  Server(8080);
  server->Init();
  server->Start();
  return 0;
}
