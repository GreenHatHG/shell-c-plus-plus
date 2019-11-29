#include <iostream>
#include "shell.h"
// 提供getcwd函数
#include <unistd.h>
using namespace std;

void pwd()
{
    char buf[120];

    /*  char *getcwd(char *buf, size_t size);
        获取当前工作目录的路径名，并将其复制到参数buf所指的size字节大小的内存空间中。
        如果无法确定目录或size太小，则返回NULL，如果成功，则返回buf。
        在GNU中，如果buf为NULL，则使用'malloc'分配一个数组。    */
    getcwd(buf, sizeof(buf));
    cout << buf << endl;
}