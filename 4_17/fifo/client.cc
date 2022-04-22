#include "common.h"
int main()
{
    int fd = open(MYFIFO,O_RDONLY);
    if(fd == -1){
        exit(1);
    }
    char buff[64];
    while(1)
    {
        ssize_t sz = read(fd,buff,sizeof(buff)-1);
        if(sz == 0){
            cout<<"远端已关闭"<<endl;
            break;
        }
        else if( sz == -1){
            perror("read error");
            exit(2);
        }
        buff[sz] = 0;
        cout <<buff<<endl;
    }
    return 0;
}
