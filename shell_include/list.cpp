#include <iostream>
#include <cstring>
#include "shell.h"
// 提供scandir函数
#include <dirent.h>
using namespace std;

void list(char* name){
    struct dirent **namelist;
    /*扫描dir目录下(不包括子目录)满足filter过滤模式的文件
        返回的结果是compare函数经过排序的，并保存在namelist中
        alphasort是为scandir最后调用qsort函数时传给qsort作为判断的函数*/
    int total = scandir(name, &namelist, 0, alphasort);
    if(total == -1){
        cout <<  "list: cannot access '" << name 
            << "': No such file or directory" << endl;
        return;
    }
    cout << "total " << total-2 << endl;
    for(int i=0; i<total; i++){
        char* d_name = namelist[i]->d_name;
        if(!(strcmp(d_name, ".") == 0 || strcmp(d_name, "..") == 0)){
            cout << d_name << endl;
            free(namelist[i]);
        }
    }
    free(namelist);
}