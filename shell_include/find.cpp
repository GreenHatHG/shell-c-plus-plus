#include <iostream>
#include <cstring>
#include <cstdio>
#include <dirent.h>
#include <regex>
#include "shell.h"
using namespace std;

void list_dir(const char* file, const char* path)
{
    DIR* dir;
	struct dirent* dirp;
	// 存放子目录的全名, 用于递归
	char childPath[500];

    if((dir = opendir(path)) != NULL)
	{
		while((dirp = readdir(dir)) != NULL)
		{
			// 如果是.和.. 不用进入里面遍历
			if(strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            {
                continue;
            } 
            // 匹配成功
			else if(strcmp(dirp->d_name, file) == 0)
            {
                printf("%s/%s\n", path, dirp->d_name);
            } 
			//如果是个子目录
			if(dirp->d_type == DT_DIR)
			{
				//得到子目录全名递归进入里面遍历
				sprintf(childPath, "%s/%s", path, dirp->d_name);
				list_dir(file, childPath);
			}
		}
		closedir(dir);
	}
}

void find()
{
    char path[100];
    char file[100];
    cin >> path >> file;
    list_dir(file, path);
}