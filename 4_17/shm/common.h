#include <iostream>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

using namespace std;

#define sz 4096
#define PATH "Makefile"
#define FLAG 0666
