#include <iostream>
#include "shell.h"
// 提供rename函数
#include <cstdio>
using namespace std;

void rename()
{
    char oldpath[100];
    char newpath[100];
    cin >> oldpath >> newpath;

    /* int rename(const char *oldpath, const char *newpath); */
    if(rename(oldpath, newpath) == 0)
    {
        cout << "successfully renamed" << endl;
    }
    else
    {
       cout << "failed to rename" << endl;
    }
     
}