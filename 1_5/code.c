#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t lock;
pthread_cond_t cond;

void* thread_run1(void* arg)
{
  while(1)
  {
    pthread_cond_wait(&cond,&lock);
    printf("pthread 1 正在运行....\n");
  }
}

void* thread_run2(void* arg)
{
  while(1)
  {
    printf("正在唤醒 pthread 1....\n");
    pthread_cond_signal(&cond);
    sleep(2);
  }
}

int main()
{
  pthread_t t1,t2;
  pthread_mutex_init(&lock,NULL);
  pthread_cond_init(&cond,NULL);
  pthread_create(&t1,NULL,thread_run1,NULL);
  pthread_create(&t2,NULL,thread_run2,NULL);


  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  pthread_mutex_destroy(&lock);
  pthread_cond_destroy(&cond);
  return 0;
}




//int count = 1000;
//pthread_mutex_t lock;
//void* grabVoter(void* val)
//{
//  int tid = (int)val;
//  while(1)
//  {
//    usleep(1000);
//    pthread_mutex_lock(&lock);
//    if(count > 0)
//    {
//      //usleep(1000);
//      printf("%d号线程抢票成功，id = %d\n",tid,count);
//      count--;
//      pthread_mutex_unlock(&lock);
//    }
//    else 
//    {
//      pthread_mutex_unlock(&lock);
//      break;
//    }
//  }
//
//}
//
//int main()
//{
//  //创建四个线程
//  int i = 0;
//  pthread_t tid[4];
//  pthread_mutex_init(&lock,NULL);
//  for(i = 0;i < 4;i++)
//  {
//    pthread_create(tid+i,NULL,grabVoter,(void*)i);
//  }
//
//  for(i = 0;i<4;i++)
//  {
//    pthread_join(tid[i],NULL);
//  }
//  pthread_mutex_destroy(&lock);
//  return 0;
//}
//

//void* pthread_run()
//{
//  int count = 0;
//  while(1)
//  {
//    printf("I am thread1 ,pid:%d,thread_ID:%p\n",getpid(),pthread_self());
//    sleep(1);
//    if(count == 5)
//      return 0;
//    count++;
//  }
//}
//int main()
//{
//  //创建多线程
//  pthread_t thread;
//  pthread_create(&thread,NULL,pthread_run,NULL);
//  while(1)
//  {
//    printf("I am main thread,pid:%d,%p\n",getpid(),thread);
//
//    sleep(2);
//  }
//  return 0;
//}

//int main()
//{
//  pthread_t tid;
//  pthread_create(&tid,NULL,pthread_run,NULL);
//
//  sleep(10);
//  void* retval = NULL;
//  //阻塞等待
//  pthread_join(tid,&retval);
//  printf("thread end:%d\n",(long long)retval);
//  return 0;
//}

//int main()
//{
//  pthread_t tid;
//  pthread_create(&tid,NULL,pthread_run,NULL);
//  sleep(5);
//  pthread_cancel(tid);
//
//  return 0;
//}


//void* pthread_run(void* val)
//{
//  pthread_detach(pthread_self());
//  while(1)
//  {
//    printf("%s\n",val);
//    sleep(1);
//    break;
//  }
//  return 10;
//}
//
//int main()
//{
//  pthread_t tid1;
//  pthread_create(&tid1,NULL,pthread_run,"thread 1");
//  sleep(10);
//  void* retval = NULL;
//  pthread_join(tid1,&retval);
//  printf("%d\n",(long long)retval);
//  return 0;
//}
