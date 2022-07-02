#include <stdio.h>
#include <stdlib.h>
#include "libusb.h"

int main()
{
    //初始化
    if(libusb_init(NULL)){
        printf("libusb_init error");
        exit(1);
    }

    struct libusb_device** list;
    ssize_t cnt = libusb_get_device_list(NULL,&list);
    printf("%d\n",cnt);
    for(ssize_t i = 0;i < cnt;i++){
        libusb_device* tmp = list[i];
        struct libusb_device_descriptor des;
        if(!libusb_get_device_descriptor(tmp,&des)){
            printf("vid:%x,pid:%d,Bus:%d,device:%d,%d\n"
                    ,des.idVendor,des.idProduct
                    ,libusb_get_bus_number(tmp)
                    ,libusb_get_device_address(tmp)
                    ,des.iProduct);
        }
    }
    //释放设备列表
    libusb_free_device_list(list,1);
    libusb_exit(NULL);
    return 0;
}
