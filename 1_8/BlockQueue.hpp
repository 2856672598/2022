#pragma once 

#include<iostream>
#include<unistd.h>
#include<queue>
#include<pthread.h>

template<class T>
class BlockQueue
{
  private:
    std::queue<T> q;
    int capacity;
    pthread_mutex_t lock;
    pthread_cond_t c_cond;//消费变量
    pthread_cond_t p_cond;//生产变量
  public:

    BlockQueue(size_t cap)
      :capacity(cap)
    {
      pthread_mutex_init(&lock,nullptr);
      pthread_cond_init(&c_cond,nullptr);
      pthread_cond_init(&p_cond,nullptr);
    }

    ~BlockQueue()
    {
      pthread_mutex_destroy(&lock);
      pthread_cond_destroy(&c_cond);
      pthread_cond_destroy(&p_cond);
    }
    bool Empty()
    {
      return q.empty();
    }

    bool Full()
    {
      return q.size()>=capacity;
    }
    void LockQueue()
    {
      pthread_mutex_lock(&lock);
    }

    void UnlockQueue()
    {
      pthread_mutex_unlock(&lock);
    }

    void Push(T t)
    {
      LockQueue();
      //当队列满了就需要通知
      while(Full())
      {
        pthread_cond_signal(&c_cond);
        pthread_cond_wait(&p_cond,&lock);
      }
      q.push(t);
      UnlockQueue();
    }

    T Pop()
    {
      LockQueue();

      while(Empty())
      {
        std::cout<<"通知生产"<<std::endl;
        pthread_cond_signal(&p_cond);
        pthread_cond_wait(&c_cond,&lock);
      }
      T t = q.front();
      q.pop();
      UnlockQueue();
      return t;
    }

};
