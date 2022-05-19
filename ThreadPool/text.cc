#include <time.h>
#include <unistd.h>
#include "ThreadPool.h"

class Task
{
private:
    int a;
    int b;

public:
    Task()
    {}
    Task(int x, int y)
        : a(x), b(y)
    {}

    void operator()()
    {
        cout<<"线程ID："<<pthread_self()<<","<< a << "+" << b << "=" << a + b << endl;
    }
};

void *Produce(void *arg)
{
    pthread_detach(pthread_self());
    ThreadPool<Task> *pool = (ThreadPool<Task> *)arg;
    while (true)
    {
        Task t(rand() % 10, rand() % 10);
        sleep(1);
        pool->Push(t);
    }
}

int main()
{
    srand((long long)time(nullptr));
    pthread_t tid;
    ThreadPool<Task> *pool = ThreadPool<Task>::GetInstance();
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&tid, nullptr, Produce, pool);
    }
    while (1);
    return 0;
}