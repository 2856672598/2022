#pragma once

#include <iostream>
#include <queue>
#include <thread>
using namespace std;

template <class T>
class ThreadPool
{
private:
    int _threadCount;
    queue<T> _queue;
    pthread_mutex_t _mlock;
    pthread_cond_t _cond;
    static ThreadPool<T> *_instance;

private:
    ThreadPool(int threadCount = 3)
        : _threadCount(threadCount)
    {
        pthread_mutex_init(&_mlock,nullptr);
        pthread_cond_init(&_cond,nullptr);
    }
    ThreadPool(const ThreadPool<T> &) = delete;
    ThreadPool& operator=(const ThreadPool<T>&)=delete;
    void Lock()
    {
        pthread_mutex_lock(&_mlock);
    }
    void Unlock()
    {
        pthread_mutex_unlock(&_mlock);
    }
    void Pop(T *t)
    {
        *t = _queue.front();
        _queue.pop();
    }
    bool Empty()
    {
        return _queue.empty();
    }

    static void *Handler(void *arg)
    {
        ThreadPool<T> *obj = (ThreadPool<T> *)arg;
        pthread_detach(pthread_self());
        while (true)
        {
            obj->Lock();
            //先获取任务，没有任务挂起
            while (obj->Empty())
            {
                pthread_cond_wait(&obj->_cond, &obj->_mlock);
            }
            T t;
            obj->Pop(&t);
            obj->Unlock();
            //处理任务
            t();
        }
    }
    void Init()
    {
        pthread_t tid;
        for (int i = 0; i < _threadCount; i++)
        {
            pthread_create(&tid, nullptr, Handler, this);
        }
    }

public:
    ~ThreadPool()
    {
        pthread_mutex_destroy(&_mlock);
        pthread_cond_destroy(&_cond);
    }

    static ThreadPool<T> *GetInstance()
    {
        static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
        if (_instance == nullptr)
        {
            pthread_mutex_lock(&mtx);
            if (_instance == nullptr)
            {
                _instance = new ThreadPool<T>;
                _instance->Init();
            }
            pthread_mutex_unlock(&mtx);
        }
        return _instance;
    }

    void Push(const T &t)
    {
        Lock();
        _queue.push(t);
        Unlock();
        //此时可能所有的线程已经全部休眠，需要唤醒一下
        pthread_cond_signal(&_cond);
    }
};

template <class T>
ThreadPool<T> *ThreadPool<T>::_instance = nullptr;
