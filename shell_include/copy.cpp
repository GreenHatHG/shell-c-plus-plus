#include <iostream>
#include <cstring>
#include <cstdio>
#include <dirent.h>
#include "shell.h"
using namespace std;

// 判断给出的路径是文件夹,还是文件
bool is_folder(const char* pathname)
{
    DIR *dp;
    if((dp = opendir(pathname)) == NULL)
    {
        return false;
    }
    closedir(dp);
    return true;
}

// 文件复制
int file_copy(const char* oldfile, const char* newfile)
{
     FILE *input,*output;
    //  判断文件是否存在
    if((input = fopen(oldfile, "r")) == NULL)
    {
        cout <<  "copy: cannot access '" << oldfile 
            << "': No such file" << endl;
        return -1;
    }
    // 判断是否可写
    if((output = fopen(newfile, "w")) == NULL)
    {
        cout << "copy: permission denied" << endl;
        return -2;
    }

    // 从流中返回一个字符值,读取一个字节后，光标位置后移一个字节
    char ch = fgetc(input);
    // 检测流上的文件结束符
    while(!feof(input))
    {
        // 将字符ch写到文件指针output所指向的文件的当前写指针的位置
        fputc(ch, output);
        ch = fgetc(input);
    }
    fclose(input);
    fclose(output);
    return 0;
}

// 文件复制到文件夹的情况
int copy_file_to_folder(const char* file, const char* folder)
{
    // 文件名称
    char file_name[100];
    // 目标文件路径
    char file_dest[100];
    // 获得源文件路径名的长度
    int file_path_length = strlen(file);

    int i; 
    for(i = file_path_length; i >= 0; i--)
    {
        if(file[i] == '/')
        {
            // 提取斜杠后的文件名
            /*char *strncpy(char *dest, const char *src, int n);
            表示把src所指向的字符串中以src地址开始的前n个字节复制到dest所指的数组中，并返回被复制后的dest*/
            strncpy(file_name, file+i+1, file_path_length-i);
            break;
        }
    }
    // 没有斜杠，路径名就是文件名
    if(i <= -1)
    {
        // strcpy把含有'\0'结束符的字符串复制到另一个地址空间
        strcpy(file_name, file); 
    }
    // 构造目标文件路径名
    strcpy(file_dest, folder);
    strcat(file_dest, "/");
    strcat(file_dest, file_name);
    return file_copy(file, file_dest);
}

void copy()
{
    char oldfile[100], newfile[100];
    cin >> oldfile >> newfile;

    if(is_folder(newfile))
    {
        if(copy_file_to_folder(oldfile, newfile) == 0)
        {
            cout << "successfully copy" << endl;
        }
    }
    else
    {
        if(file_copy(oldfile, newfile) == 0)
        {
            cout << "successfully copy" << endl;
        }
    }
}