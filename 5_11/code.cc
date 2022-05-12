#include <iostream>
#include <unistd.h>
using namespace std;

class Print
{
    private:
        int _begin;
        pthread_mutex_t _mlock;
        pthread_cond_t _EvenCond;
        pthread_cond_t _OddCond;
    private:
        void Lock()
        {
            pthread_mutex_lock(&_mlock);
        }
        void Unlock()
        {
            pthread_mutex_unlock(&_mlock);
        }
    public:
        Print(int begin)
            :_begin(begin)
        {
            pthread_mutex_init(&_mlock,nullptr);
            pthread_cond_init(&_EvenCond,nullptr);
            pthread_cond_init(&_OddCond,nullptr);
        }
        ~Print()
        {
            pthread_mutex_destroy(&_mlock);
        }

    public:
        void PrintEven()
        {
            while(1)
            {
                Lock();
                pthread_cond_wait(&_EvenCond,&_mlock);
                cout<<pthread_self()<<":"<<_begin<<endl;
                _begin++;
                pthread_cond_signal(&_OddCond);
                Unlock();
            }
        }
        void PrintOdd()
        {
            while(1)
            {
                Lock();
                cout<<pthread_self()<<":"<< _begin<<endl;
                _begin++;
                pthread_cond_signal(&_EvenCond);
                pthread_cond_wait(&_OddCond,&_mlock);
                sleep(1);
                Unlock();
            }
        }
};

void* Odd(void*args)
{
    Print* p = (Print*)args;
    p->PrintOdd();
    return nullptr;
}

void* Even(void* args)
{
    Print* p = (Print*)args;
    p->PrintEven();
    return nullptr;
}

int main()
{
    Print p(0);
    pthread_t tid;
    pthread_create(&tid,nullptr,Even,&p);
    pthread_create(&tid,nullptr,Odd,&p);
    while(1);
    return 0;
}


//#include <iostream>
//#include <vector>
//#include <unistd.h>
//#include <pthread.h>
//using namespace std;
//
//class Ticket
//{
//    private:
//        int ticket;
//        pthread_mutex_t mlock;
//    public:
//        Ticket(int num)
//            :ticket(num)
//        {
//            pthread_mutex_init(&mlock,nullptr);
//        }
//        ~Ticket()
//        {
//            pthread_mutex_destroy(&mlock);
//        }
//        bool GetTicket()
//        {
//            pthread_mutex_lock(&mlock);
//            if(ticket>0){
//                cout<<pthread_self()<<"抢票成功，票id："<<ticket<<endl;
//                ticket--;
//            }else{
//                cout<<"抢票失败"<<endl;
//                pthread_mutex_unlock(&mlock);
//                return false;
//            }
//            pthread_mutex_unlock(&mlock);
//            return true;
//        }
//};
//
//void* ThreadRun(void* arg)
//{
//    Ticket* t = (Ticket*)arg;
//    while(true)
//    {
//        if(!t->GetTicket())
//            break;
//        usleep(1000);
//    }
//    return nullptr;
//}
//
//int main()
//{
//    Ticket* t = new Ticket(1000);
//    vector<pthread_t>arr;
//    for(int i = 0;i<5;i++)
//    {
//        pthread_t tid;
//        pthread_create(&tid,nullptr,ThreadRun,t);
//       arr.push_back(tid); 
//    }
//    for(int i = 0;i<5;i++)
//    {
//        pthread_join(arr[i],nullptr);
//    }
//    delete t;
//    return 0;
//}
