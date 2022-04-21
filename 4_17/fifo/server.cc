#include "common.h" 

int main()
{
    if(mkfifo(MYFIFO,0666) == -1){
        perror("管道文件已存在");
        exit(1);
    }

    int fd = open(MYFIFO,O_WRONLY);
    char str[64];
    while(1)
    {
        cout<<"请输入#";
        fflush(stdout);
        cin >> str;
        write(fd,str,strlen(str));
    }
    return 0;
}
