#include "BlockQueue.hpp"
using namespace std;

void* ProducerRun(void*q)
{
  sleep(1);
  BlockQueue<int>* pq = (BlockQueue<int>*)q;
  int count = 0;
  while(1)
  {
    count = count%10 + 1;
    pq->Push(count);
    cout<<"正在生产:"<<count<<endl;
    sleep(1);
  }
}

void* ConsumerRun(void* q)
{
  BlockQueue<int>* pq = (BlockQueue<int>*)q;
  int ret = 0;
  while(1)
  {
    ret = pq->Pop();
    cout<<"取货成功："<<ret<<endl;
  }
}
int main()
{
  BlockQueue<int>* q = new BlockQueue<int>(10);
  pthread_t t1,t2;
  pthread_create(&t1,nullptr,ProducerRun,q);
  pthread_create(&t2,nullptr,ConsumerRun,(void*)q);

  pthread_join(t1,nullptr);
  pthread_join(t2,nullptr);
  return 0;
}
