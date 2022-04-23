#include "common.h"

int main()
{
    //使用同一个key
    key_t key = ftok(PATH,FLAG);
    if(key == -1){
        perror("ftok error");
        exit(1);
    }
    //获取shmid
    int shmid = shmget(key,sz,IPC_CREAT);
    if(shmid< 0){
        perror("shmget error");
        exit(2);
    }

    //绑定
    char* shmaddr = (char*)shmat(shmid,NULL,SHM_RDONLY);

    while(1){
        printf("%s\n",shmaddr);
        sleep(1);
    }
    
    shmdt((void*)shmaddr);
    return 0;
}
