#include"ThreadPool.hpp"
using namespace std;

int main()
{
  ThreadPool<Task>*q = new ThreadPool<Task>(20);
  int count = 0;
  q->ThreadPoolInit();
  while(1)
  {
    Task t(count);
    count++;
    count%=10+1;
    q->Put(t);
    usleep(100);
  }
  return 0;
}
