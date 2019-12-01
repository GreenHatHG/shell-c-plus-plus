#include <iostream>
#include "shell.h"
// 提供rename函数
#include <cstdio>
#include <cerrno>
#include <cstring>
using namespace std;

void myrename(char* oldpath, char* newpath)
{
    errno = 0;
    /* int rename(const char *oldpath, const char *newpath); */
    int result = rename(oldpath, newpath);
    if(result != 0){
         cout << "rename: cannot rename '" << oldpath << "': " << 
            strerror(errno) << endl;
    }
}