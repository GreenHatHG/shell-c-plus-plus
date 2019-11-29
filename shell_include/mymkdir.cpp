#include <iostream>
#include "shell.h"
// 提供mkdir函数
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

void mymkdir()
{
    char pathname[100];
    cin >> pathname;

    /* int mkdir(const char *pathname, mode_t mode); */
    if(mkdir(pathname, 0755) == 0)
    {
        cout << "mkdir success" << endl;
    }
    else
    {
        cout << "mkdir failure" << endl;
    }
}