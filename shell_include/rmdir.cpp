#include <iostream>
#include "shell.h"
// 提供rmdir函数
#include <unistd.h>
#include <cerrno>
#include <cstring>
// 提供nftw,remove函数
#include <ftw.h>
using namespace std;

int rmFiles(const char *pathname, const struct stat *sbuf, int type, struct FTW *ftwb){
    if(remove(pathname) < 0){
        return -1;
    }
    return 0;
}

void rmdir(char* path){
    errno = 0;
    /* 遍历位于目录path下的目录树，并对树中的每个条目调用一次rmFiles
        第三个参数10为同时保持打开状态的最大目录数。当搜索深度超过此深度时，
        nftw()会变慢，因为必须关闭目录并重新打开。
        FTW_DEPTH 执行深度优先搜索. 在遍历此目录前先将所有子目录遍历完
        FTW_PHYS 不要遍历符号连接的目录. 预设会遍历符号连接目
        FTW_MOUNT 遍历时不要跨越到其他文件系统*/
    if (nftw(path, rmFiles, 10 , FTW_DEPTH|FTW_MOUNT|FTW_PHYS) < 0){
         cout << "rmdir: cannot remove '" << path << "': " << 
            strerror(errno) << endl;
    }
}