#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void* threadRun(void*)
{
    int count =0;
    while(1)
    {
        count++;
        cout<<"我是一个新线程"<<endl;
        sleep(1);
        if(count == 5){
            pthread_exit((void*)10);
        }
    }
}

int main()
{
    pthread_t tid;
    pthread_create(&tid,nullptr,threadRun,nullptr);
    void* retval;
    sleep(10);
    pthread_join(tid,&retval);
    printf("%d\n",retval);
    return 0;
}


//void* threadRun(void*)
//{
//    int count = 0;
//    while(1){
//        cout<<"我是一个新线程，线程ID是："<<pthread_self()<<endl;
//        sleep(1);
//        if(count == 5){
//            //线程退出
//            return (void*)10;
//        }
//        count++;
//    }
//}
//int main()
//{
//    pthread_t tid;
//    pthread_create(&tid,nullptr,threadRun,nullptr);
//    int* retval;
//    pthread_join(tid,(void**)&retval);
//    printf("线程的退出码是：%d",retval);
//    return 0;
//}



//#include <iostream>
//#include <signal.h>
//#include <unistd.h>
//using namespace std;
//
//void sigch(int signo)
//{
//    cout<<"收到"<<signo<<"信号"<<endl;
//}
//int main()
//{
//    signal(2,sigch);
//    while(1);
//    return 0;
//}

//#include <iostream>
//#include <signal.h>
//using namespace std;
//
//void sigcb(int signo)
//{
//    cout<<"收到"<<signo<<"信号"<<endl;
//}
//
//int main()
//{
//    struct sigaction act;
//    act.sa_handler = sigcb;
//    sigaction(2,&act,nullptr);
//    while(1);
//    return 0;
//}
//


//#include <iostream>
//#include <signal.h>
//using namespace std;
//
//int main()
//{
//    sigset_t set;
//    sigaddset(&set,2);
//    sigaddset(&set,40);
//    sigprocmask(SIG_SETMASK,&set,nullptr);
//    while(1);
//    return 0;
//}
//
//#include <iostream>
//#include <unistd.h>
//#include <signal.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//using namespace std;
//
//void handler(int signo)
//{
//    cout<<"收到："<<signo<<"信号"<<endl;
//    waitpid(-1,nullptr,0);
//}
//
//int main()
//{
//    signal(17,SIG_IGN);
//    if(fork() == 0){
//        int num = 0;
//        while(num < 5){
//            num++;
//            cout<<"num："<<num<<endl;
//            sleep(1);
//        }
//        exit(1);
//    }
//    while(1);
//    return 0;
//}
