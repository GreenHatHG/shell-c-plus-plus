#include <iostream>
#include "shell.h"
// 提供mkdir函数
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

void mkdir()
{
    char pathname[100];
    cin >> pathname;

    /* int mkdir(const char *pathname, mode_t mode); */
    if(mkdir(pathname, 0755) == 0)
    {
        cout << "successfully mkdired" << endl;
    }
    else
    {
        cout << "failed to mkdir" << endl;
    }
}