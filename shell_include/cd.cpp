#include <iostream>
#include "shell.h"
// 提供chdir函数
#include <unistd.h>
#include <cerrno>
#include <cstring>
using namespace std;

void cd(char* path){
    /* int chdir(const char *path); 
        更改调用进程的当前工作目录 */
    errno = 0;
    int result = chdir(path);
    if(result == -1){
        cout << "cd: " <<
            strerror(errno) << endl;
    }
}