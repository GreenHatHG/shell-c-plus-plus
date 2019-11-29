#include <iostream>
#include <cstring>
#include "shell.h"
// 提供opendir,readdir函数
#include <dirent.h>
using namespace std;

void list()
{
    char name[100];
    cin >> name;

    /* DIR * opendir(const char * name); 
        打开参数name指定的目录，并返回DIR*形态的目录流，如果无法打开，则返回NULL*/
    DIR* dir = opendir(name);
    if(dir == NULL)
    {
        cout <<  "list: cannot access '" << name 
            << "': No such file or directory" << endl;
        return;
    }

    struct dirent* dirp;
    /* struct dirent * readdir(DIR * dir);
        成功则返回下个目录进入点。有错误发生或读取到目录文件尾则返回NULL */
    while((dirp = readdir(dir)) != NULL)
    {
        // 去除不需要输出的符号
        if(!(strcmp(dirp->d_name, ".") == 0 
            || strcmp(dirp->d_name, "..") == 0))
        {
            cout << dirp->d_name << endl;
        }
    }
}