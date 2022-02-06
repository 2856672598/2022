#include<iostream>
#include<queue>
#include<pthread.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<map>
class Task
{
  public:
    Task(int sock = 0)
      :_sockfd(sock)
    {
      m.insert(std::pair<std::string,std::string>("apple","苹果"));
    }

    ~Task()
    {
      close(_sockfd);
    }
    void run()
    {
      std::cout<<"正在运行"<<std::endl;
      char buff[128];
      std::cout<<_sockfd<<std::endl;
      ssize_t sz = recv(_sockfd,buff,sizeof(buff)-1,0);
      if(sz > 0)
      {
        buff[sz] = 0;
        std::cout<<buff<<std::endl;
        //send(_sockfd,buff,sz,0);
        auto it = m.find(buff);
        if(it != m.end())
        {
          send(_sockfd,it->second.c_str(),it->second.size(),0);
        }
      }
    }

  private:
    int _sockfd;
    std::map<std::string,std::string>m;
};

template <class T>
class ThreadPool
{
  public:
    ThreadPool(int capacity = 10)
      :_capacity(capacity)
    {}

    static void* Routine(void* arg)
    {
      ThreadPool* tp = (ThreadPool*)arg;
        tp->LockQueue();
      while(true)
      {

      
      while(tp->q.empty())
      {
        //队列为空
        pthread_cond_wait(&tp->cond,&tp->lock);
      }

      T* t = tp->Get();
      tp->UnLockQueue();
      t->run();
      delete t;
      }
    }


    void Init()
    {
      //创建一批线程
      pthread_mutex_init(&lock,NULL);
      pthread_cond_init(&cond,NULL);
      pthread_t fd;
      for(int i =0;i<_capacity;i++)
      {
        pthread_create(&fd,nullptr,Routine,this);
      }
    }

    void LockQueue()
    {
      pthread_mutex_lock(&lock);
    }

    void UnLockQueue()
    {
      pthread_mutex_unlock(&lock);
    }

    void Push(T* in)
    {
      LockQueue();
      q.push(in);
      UnLockQueue();
      pthread_cond_signal(&cond);
    }

    T* Get()
    {
      T* tmp;
      //LockQueue();
      tmp = q.front();
      q.pop();
      //UnLockQueue();
      return tmp;
    }

  private:
    int _capacity;
    std::queue<T*>q;
    pthread_mutex_t lock;
    pthread_cond_t cond;
};
