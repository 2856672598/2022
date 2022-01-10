#pragma once 
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <vector>
#include <semaphore.h>

template<class T>
class RingQueue
{
  private:
    std::vector<T> v;
    size_t capacity;
    sem_t date_sem;//数据
    sem_t space_sem;//空间
    size_t producer_index;
    size_t consumer_index;
  public:
    RingQueue(int cap = 10)
      :capacity(cap)
    {
      v.resize(capacity);
      sem_init(&date_sem,0,0);
      sem_init(&space_sem,0,capacity);
      producer_index = consumer_index  = 0;
    }
    ~RingQueue()
    {
      sem_destroy(&date_sem);
      sem_destroy(&space_sem);
    }

    void Push(T& val)
    {
      sem_wait(&space_sem);
      v[producer_index] = val;
      producer_index = (producer_index+1)%capacity;
      sem_post(&date_sem);
    }

    void Pop(T& val)
    {
      sem_wait(&date_sem);
      val = v[consumer_index];
      consumer_index = (consumer_index+1)%capacity;
      sem_post(&space_sem);
    }
};
