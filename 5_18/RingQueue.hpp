#pragma once
#include <iostream>
#include <vector>
#include <atomic>
#include <semaphore.h>
using namespace std;

template <class T>
class RingQueue
{
private:
    int _capacity;
    int _head;
    int _tail;
    sem_t _position; //空位置
    sem_t _data;     //数据
    vector<T> _queue;
    pthread_mutex_t _pushLock;
    pthread_mutex_t _popLock;

public:
    RingQueue(int capacity = 10)
        : _capacity(capacity), _queue(_capacity), _head(0), _tail(0)
    {
        sem_init(&_position, 0, _capacity);
        sem_init(&_data, 0, 0);
        pthread_mutex_init(&_pushLock, nullptr);
        pthread_mutex_init(&_popLock, nullptr);
    }
    ~RingQueue()
    {
        sem_destroy(&_position);
        sem_destroy(&_data);
        pthread_mutex_destroy(&_pushLock);
        pthread_mutex_destroy(&_popLock);
    }

public:
    void Push(const T &val)
    {
        //申请位置信号量
        sem_wait(&_position);

        pthread_mutex_lock(&_pushLock);
        _queue[_tail++] = val;
        _tail %= _capacity;
        pthread_mutex_unlock(&_pushLock);

        cout << "生产一个数据：" << val << endl;
        sem_post(&_data); //此时数据加一
    }

    void Pop(T *val)
    {
        //申请_data信号量
        sem_wait(&_data);
        pthread_mutex_lock(&_popLock);
        *val = _queue[_head++];
        _head %= _capacity;
        pthread_mutex_unlock(&_popLock);
        sem_post(&_position);
    }
};