#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
int main()
{
  int fd = open("fifo",O_WRONLY);
  while(1)
  {
    printf("请输入>");
    fflush(stdout);
    char buff[64];
    ssize_t sz = read(0,buff,sizeof(buff));
    buff[sz] = 0;
    write(fd,buff,strlen(buff));
  }
  return 0;
}
