#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include"comm.h"

int main()
{
  //创建共享内存
  key_t k = ftok(PATHNAME,PROJ);
  int shmid = shmget(k,SIZE,IPC_CREAT|0666);
  //连接到进程地址空间
  char* str =(char*)shmat(shmid,NULL,0);
  int i = 'a';
  while(i <= 'z')
  {
    str[i-'a'] = i;
    i++;
    str[i] = 0;
    sleep(1);
  }
  shmdt(str);
  return 0;
}
