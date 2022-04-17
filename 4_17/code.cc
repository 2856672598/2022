#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;
int main()
{
    int pipefd[2];
    pipe(pipefd);
    int pid = fork();
    if(pid == 0){
        close(pipefd[0]);
        int count = 0;
        while(1)
        {
            write(pipefd[1],"a",1);
            count++;
            cout<<"count:"<<count<<endl;
        }
    }
    else{
        close(pipefd[1]);
        char buff[1025];
        sleep(5);
        while(true)
        {
            sleep(1);
            ssize_t sz = read(pipefd[0],buff,1024);
            buff[sz] = 0;
            //防止刷屏只输出一个字符
            cout<<buff[0]<<endl;
        }
    }
    return 0;
}



////当读端关闭时
//int main()
//{
//    int pipefd[2];
//    if(pipe(pipefd)== -1)
//        exit(1);
//
//    int pid = fork();
//    if(pid == 0){
//        //子进程向管道写入
//        close(pipefd[0]);
//        int count = 5;//当写入5条数据后关闭写端
//        while(count--)
//        {
//            write(pipefd[1],"a",1);
//        }
//        close(pipefd[1]);
//        cout<<"写端关闭"<<endl;
//    }
//    else{
//        close(pipefd[1]);
//        char ch;
//        while(1)
//        {
//            ssize_t sz = read(pipefd[0],&ch,1);
//            if(sz == 0){
//                cout<<"write close..."<<endl;
//            }
//            else
//                cout<<ch<<endl;
//            sleep(1);
//        }
//    }
//    return 0;
//}



////当读端关闭时，写端会收到13号信号
//int main()
//{
//    int pipefd[2];
//    if(pipe(pipefd) == -1)
//        exit(1);
//    int pid = fork();
//    if(pid == 0){
//        //child--->写入数据
//        close(pipefd[0]);
//        const char* str = "hello world";
//        while(true)
//        {
//            write(pipefd[1],str,strlen(str));
//            cout <<"写入数据..."<<endl;
//            sleep(1);
//        }
//    }
//    else{
//        close(pipefd[1]);//parent-->从管道读取数据
//        int count = 3;//只读取三次数据
//        char buff[64]="0";
//        while(count--)
//        {
//            ssize_t sz = read(pipefd[0],buff,sizeof(buff)-1);
//            buff[sz] = 0;
//            if(sz == 0){
//                //写段关闭
//                cout <<"child closr...."<<endl;
//                break;
//            }
//            cout << buff << endl;
//        }
//        close(pipefd[0]);
//        cout <<"读端退出"<<endl;
//    }
//    int state = 0;
//    waitpid(-1,&state,0);
//    //输出下子进程的退出码和是否收到信号
//    cout <<"退出码："<< ((state >> 8)&0xff)<<endl;
//    cout <<"信号："<<(state &0x7f)<<endl;
//    return 0;
//}



//int main()
//{
//    int pipefd[2];
//    if(pipe(pipefd) == -1)
//        exit(1);
//
//    //匿名管道用于父子间进程
//    int pid = fork();
//    if(pid == 0){
//        //子进程进行向管道写入数据
//        close(pipefd[0]);//写入数据关闭读端
//        while(true)
//        {
//            const char* str = "hello world";
//            write(pipefd[1],str,strlen(str));
//            sleep(1);
//        }
//    }
//    close(pipefd[1]);//父进程关闭写端
//    while(1)
//    {
//        //父进程读取从管道读取数据
//        char buff[64] = {0};
//        ssize_t sz = read(pipefd[0],buff,sizeof(buff)-1);
//        cout<<"child say to father:"<<buff<<endl;
//    }
//    return 0;
//}
