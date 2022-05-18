#include <time.h>
#include "RingQueue.hpp"
#include <pthread.h>
#include <unistd.h>

void *Consumer(void *argc)
{
    pthread_detach(pthread_self());
    RingQueue<int> *q = (RingQueue<int> *)argc;
    while (true)
    {
        int val;
        q->Pop(&val);
        sleep(1);
        cout << "消费一个数据：" << val << endl;
    }
}

void *Producer(void *argc)
{
    pthread_detach(pthread_self());
    RingQueue<int> *q = (RingQueue<int> *)argc;
    while (true)
    {
        int val = rand() % 20;
        q->Push(val);
    }
}

int main()
{
    srand((long long)time(nullptr));
    pthread_t p, c;
    RingQueue<int> *q = new RingQueue<int>;
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&p, nullptr, Producer, (void *)q);
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&c, nullptr, Consumer, (void *)q);
    }
    while (1)
        ;
    return 0;
}