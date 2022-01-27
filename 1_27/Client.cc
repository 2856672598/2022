#include"Client.hpp"

int main()
{
  Client* client = new Client;
  client->InitClient();
  client->Start();
  return 0;
}
