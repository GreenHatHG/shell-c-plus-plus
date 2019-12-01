#include <iostream>
#include "shell.h"
// 提供mkdir函数
#include <sys/stat.h>
#include <sys/types.h>
#include <cerrno>
#include <cstring>
using namespace std;

void mkdir(char* path){
    /* int mkdir(const char *pathname, mode_t mode); */
    errno = 0;
    int dir_result = mkdir(path, 0755);
    if(dir_result != 0){
        cout << "mkdir: cannot create directory '" << path << "': " <<
            strerror(errno) << endl;
    }
}