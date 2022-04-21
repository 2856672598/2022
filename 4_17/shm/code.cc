#include <iostream>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
using namespace std;

#define sz 4096
int main()
{
    //创建共享内存
    key_t key = ftok("Makefile",0666);
    if(key == -1){
        perror("ftok error");
        exit(1);
    }
    int id =shmget(key,sz,IPC_CREAT|IPC_EXCL);
    cout <<"key:"<<key<<" id:"<<id<<endl;
    if(id == -1){
        perror("shmget error");
        exit(2);
    }
    sleep(10);
    shmctl(id,IPC_RMID,NULL);
    return 0;
}
