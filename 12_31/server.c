#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{
  mkfifo("./fifo",0666);
  int fd = open("fifo",O_RDONLY);
  while(1)
  {
    char buff[64];
    ssize_t sz = read(fd,buff,sizeof(buff)-1);
    buff[sz] = 0;
    if(sz > 0)
      printf("client:%s\n",buff);
  }
  return 0;
}
