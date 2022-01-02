#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include"comm.h"

int main()
{
  //创建共享内存
  key_t k = ftok(PATHNAME,PROJ);
  int shmid = shmget(k,SIZE,IPC_CREAT| IPC_EXCL | 0666);
  printf("%d\n",shmid);
  //连接到进程地址空间
  char* str =(char*)shmat(shmid,NULL,0);
  int i = 0;
  str[0]=0;
  while(1)
  {
    printf("%s\n",str);
    sleep(1);
    if(i ==40)
    {
      shmdt(str);
      shmctl(shmid,IPC_RMID,NULL);
      break;
    }
    i++;
  }
  return 0;
}
