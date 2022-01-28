#include "Server.hpp"
using namespace std;
int main(int argc, char* argv[])
{
  if(argc!=2)
    exit(1);

  Server* s = new Server(atoi(argv[1]));
  s->InitServer();
  s->Start();
  return 0;
}

