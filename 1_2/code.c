#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

//int main()
//{
//  pid_t id = getpid();
//  //通过给某个进程发信号
//  kill(id,9);
//  printf("can you see me\n");
//  return 0;
//}

//int main()
//{
//  //给自己发信号
//  raise(9);
//  printf("can you see me\n");
//  return 0;
//}

//void handler(int sig)
//{
//  printf("signal id = %d\n",sig);
//}
//int main()
//{
//  signal(6,handler);
//  abort();
//  printf("can you see me\n");
//  return 0;
//}

//int count = 0; void handler(int sig)
//{
//  printf("count = %d\n",count);
//  //exit(0);
//}
//int main()
//{
//  signal(14,handler);
//  alarm(2);
//  int i=0;
//  while(1)
//  {
//    count++;
//    if(i==10)
//      break;
//    i++;
//    sleep(1);
//  }
//  printf("%d\n",count);
//  return 0;
//}

//void handler(int sig)
//{
//  printf("signal id =%d\n",sig);
//}
//int main()
//{
//  //验证ctrl+c
//  signal(2,handler);
//  while(1);
//}

void showSet(const sigset_t* set)
{
  int i = 0;
  for(i = 1;i < 32;i++)
  {
    //printf("%d\n",i);
    if(sigismember(set,i))
      printf("1");
    else 
      printf("0");
  }
  printf("\n");
}

int main()
{
  sigset_t set;
  //初始化集合
  sigemptyset(&set);
  //将2号信号进行阻塞
  sigaddset(&set,2);
  sigprocmask(SIG_BLOCK,&set,NULL);

  sigset_t pSet;
  while(1)
  {
    sigpending(&pSet);
    showSet(&pSet);
    sleep(1);
  }
  return 0;
}
