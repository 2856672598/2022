#include "RingQueue.hpp"

using namespace std;

void* Producer(void*arg)
{
  cout<<"hello"<<endl;
  int count = 0;
  RingQueue<int>* pq = (RingQueue<int>*)arg;
  while(true)
  {
    cout<<"正在生产"<<count<<endl;
    pq->Push(count);
    count++;
    sleep(2);
  }
}

void* Consumer(void* arg)
{
  RingQueue<int>* pq = (RingQueue<int>*)arg;
  while(true)
  {
    int ret;
    pq->Pop(ret);
    cout<<"购买成功:"<<ret<<endl;
  }
}

int main()
{
  pthread_t tid1,tid2;
  RingQueue<int>q(10);
  pthread_create(&tid1,nullptr,Consumer,&q);
  pthread_create(&tid2,nullptr,Producer,&q);

  pthread_join(tid1,nullptr);
  pthread_join(tid2,nullptr);
  return 0;
}
