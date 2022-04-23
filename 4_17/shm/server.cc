#include "common.h"
int main()
{
    //创建共享内存
    key_t key = ftok(PATH,FLAG);
    if(key == -1){
        perror("ftok error");
        exit(1);
    }
    int id =shmget(key,sz,IPC_CREAT|IPC_EXCL|0666);
    cout <<"key:"<<key<<" id:"<<id<<endl;
    if(id == -1){
        perror("shmget error");
        exit(2);
    }

    //进行关联
    char* shmadd = (char*)shmat(id,NULL,SHM_RND);
    sleep(5);
    char ch ='A';
    while(ch <='Z'){
        shmadd[ch - 'A'] = ch;
        ch++;
        shmadd[ch-'A'] = 0;
        sleep(1);
    }
    //取消关联
    if( shmdt((void*)shmadd)== -1){
        perror("shmdt error");
        exit(3);
    }
    sleep(10);
    shmctl(id,IPC_RMID,NULL);
    return 0;
}
