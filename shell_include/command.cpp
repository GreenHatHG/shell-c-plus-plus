#include <iostream>
// 提供getpwuid函数
#include <sys/types.h>
#include <pwd.h>
// 提供uname函数
#include <sys/utsname.h>
// 提供getcwd函数
#include <unistd.h>
// 提供getline函数
#include <cstdio>
#include "shell.h"
using namespace std;

void print_prompt()
{
    // 调用uname获取系统信息
    struct utsname buf;
    // 获取有关当前内核的名称和信息
    uname(&buf);
    // 通过用户的uid查找用户的passwd数据
    struct passwd* info = getpwuid(getuid());
    // 保存当前路径 
    char cwd[100];  
    // 调用 getcwd 获取当前路径名，并存储在 cwd 指向的字符串
    getcwd(cwd, sizeof(cwd));
    //禁用 buffer， 直接将 printf 要输出的内容输出
    setbuf(stdout, NULL); 
    // 输出用户名,系统名称,当前路径      
    printf("<%s@%s:%s> ",info->pw_name,buf.sysname, cwd);
}

// 扫描用户输入的命令行
void scan_command(char* command)
{
    int bytes_read;
    size_t nbytes = 100;
    // 从标准输入中读入包含多条命令行语句的字符串，并保存在 command变量中
    bytes_read = getline(&command, &nbytes, stdin); 
    bytes_read -= 1;
    command[bytes_read] = '\0';
}