#pragma once 
#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<queue>

class Task
{
  private:
    int val;
  public:
    Task(int data = 10)
      :val(data)
    {}

    void Run()
    {
      std::cout<<"pthread id :"<<pthread_self()<<"pow("<<val<<")"<<val*val<<std::endl;
    }
};

template<class T>
class ThreadPool
{
  private:
    std::queue<T*> q;
    size_t capacity;
    pthread_mutex_t lock;
    pthread_cond_t cond;
  public:
    ThreadPool(int cap)
      :capacity(cap)
    {}

    void LockQueue()
    {
      pthread_mutex_lock(&lock);
    }

    void UnlockQueue()
    {
      pthread_mutex_unlock(&lock);
    }

    bool IsEmpty()
    {
      return q.size() == 0;
    }
    void Get(T& t)
    {
      T*tmp = q.front();
      q.pop();
      t = *tmp;
    }

    void Put(T& in)
    {
      LockQueue();
      q.push(&in);
      UnlockQueue();
      pthread_cond_signal(&cond);
    }

    void HangWait()
    {
      pthread_cond_wait(&cond,&lock);
    }

    static void* Routine(void* arg)
    {
      pthread_detach(pthread_self());
      ThreadPool* tp =(ThreadPool*)arg;
      while(true)
      {
        tp->LockQueue();
        while(tp->IsEmpty())
        {
          //任务队列为空了，进行挂起
          tp->HangWait();
        }
        T t;
        tp->Get(t);
        tp->UnlockQueue();
        t.Run();
      }
    }

    void ThreadPoolInit()
    {
      pthread_mutex_init(&lock,nullptr);
      pthread_cond_init(&cond,nullptr);
      pthread_t  tid;
      for(int i=0;i<capacity;i++)
      {
        pthread_create(&tid,nullptr,Routine,this);
      }
    }

    ~ThreadPool()
    {
      pthread_mutex_destroy(&lock);
      pthread_cond_destroy(&cond);
    }

};
