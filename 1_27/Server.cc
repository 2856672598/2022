#include "Server.hpp"
using namespace std;
int main()
{
  Server* s = new Server;
  s->InitServer();
  s->Start();
  return 0;
}

