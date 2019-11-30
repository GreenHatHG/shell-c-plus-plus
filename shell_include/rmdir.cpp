#include <iostream>
#include "shell.h"
// 提供rmdir函数
#include <unistd.h>
using namespace std;

void rmdir()
{
    char pathname[100];
    cin >> pathname;

    /* int rmdir(const char *pathname); */
    if(rmdir(pathname) == 0)
    {
        cout << "successfully deleted" << endl;
    }
    else
    {
        cout << "failed to delete" << endl;
    }
       
}