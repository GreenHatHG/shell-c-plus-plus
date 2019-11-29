#include <iostream>
#include "shell.h"
// 提供chdir函数
#include <unistd.h>
using namespace std;

void cd()
{
    char path[100];
    cin >> path;
    /* int chdir(const char *path); 
        更改调用进程的当前工作目录 */
    if(chdir(path) == -1)
    {
        cout << "cd: no such file or directory: " << path << endl;
    }
    else
    {
        cout << "You are now in the ";
        pwd();
    }
}