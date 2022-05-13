#include <iostream>
#include <queue>
#include <ctime>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;

template<class T>
class BlockingQueue
{
    private:
        int _capacity;
        queue<T>_queue;
        pthread_mutex_t _mlock;
        pthread_cond_t _pcond;
        pthread_cond_t _ccond;
    private:
        void Lock()
        {
            pthread_mutex_lock(&_mlock);
        }
        void Unlock()
        {
            pthread_mutex_unlock(&_mlock);
        }
        bool Empty()
        {
            return _queue.empty();
        }
        bool Full()
        {
            return _queue.size() == _capacity;
        }
    public:
        BlockingQueue(int capacity)
            :_capacity(capacity)
        {
            pthread_mutex_init(&_mlock,nullptr);
            pthread_cond_init(&_pcond,nullptr);
            pthread_cond_init(&_ccond,nullptr);
        }
        ~BlockingQueue()
        {
            pthread_mutex_destroy(&_mlock);
            pthread_cond_destroy(&_ccond);
            pthread_cond_destroy(&_pcond);
        }

    public:
        void Push(const T& val)
        {
            Lock();
            while(Full()){
                //队列满了通知消费者来消费
                pthread_cond_signal(&_ccond);
                //当生产条件满足时在唤醒生产
                pthread_cond_wait(&_pcond,&_mlock);
            }
            _queue.push(val);
            Unlock();
        }
        void Pop(T* val)
        {
            Lock();
            while(Empty()){
                //没有商品了，通知生产者生产
                pthread_cond_signal(&_pcond);
                pthread_cond_wait(&_ccond,&_mlock);
            }
            *val = _queue.front();
            _queue.pop();
            Unlock();
        }
};

void* Consumer(void* args)
{
    BlockingQueue<int>* q = (BlockingQueue<int>*)args;
    while(true)
    {
        int val;
        q->Pop(&val);
        sleep(1);
        cout<<"消费者消费了一个数据："<<val<<endl;
    }
}

void* Producer(void* args)
{
    BlockingQueue<int>*q = (BlockingQueue<int>*)args;
    while(true)
    {
        int val = rand()%10;
        q->Push(val);
        cout<<"生产者生产了一个数据："<<val<<endl;
    }
}
int main()
{
    srand((long long)time(nullptr));
    pthread_t tid;
    BlockingQueue<int>q(5);
    pthread_create(&tid,nullptr,Consumer,&q);
    pthread_create(&tid,nullptr,Producer,&q);
    while(1);
    return 0;
}
