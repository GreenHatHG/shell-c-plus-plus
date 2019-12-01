#include <iostream>
#include <string>
// 提供getpwuid函数
#include <sys/types.h>
#include <pwd.h>
// 提供uname函数
#include <sys/utsname.h>
// 提供getcwd函数
#include <unistd.h>
// 提供readline,add_history函数
#include <editline/readline.h>
// 提供strtok函数
#include <cstring>
#include "shell.h"
#include <vector>
using namespace std;

// 解析用户输入的命令
void execute(char* command){
    char tmp[100];
    strcpy(tmp, command);
    char* com1 = strtok(command, " ");
    if(com1 == NULL){
        return;
    }
    if (strcmp(com1, "exit") == 0){
		cout << "正在退出解析器···" << endl;
		exit(0);
	}
    else if(strcmp(com1, "pwd") == 0){
        pwd();
    }
    else if(strcmp(com1, "list") == 0){
        char* pathname = strtok(NULL, " ");
        if(pathname == NULL){
            list((char*)".");
        }
        else{
            list(pathname);
        }
    }
    else if(strcmp(com1, "cd") == 0){
        char* pathname = strtok(NULL, " ");
        if(pathname == NULL){
            cd((char*)".");
        }
        else{
            cd(pathname);
        }
    }
    else if(strcmp(com1, "mkdir") == 0){
        char* com2 = strtok(NULL, " ");
        while(com2){
            mkdir(com2);
            com2 = strtok(NULL, " ");
        }
    }
    else if(strcmp(com1, "rmdir") == 0){
        char* com2 = strtok(NULL, " ");
        while(com2){
            rmdir(com2);
            com2 = strtok(NULL, " ");
        }
    }
    else if(strcmp(com1, "rename") == 0){
        char* com2 = strtok(NULL, " "); 
        if(com2){
            char* com3 = strtok(NULL, " "); 
        myrename(com2, com3);
        }    
    }
    else if(strcmp(com1, "copy") == 0){
        vector<char*> command_list;
        char* com2 = strtok(NULL, " ");
        while(com2){
            command_list.push_back(com2);
            com2 = strtok(NULL, " ");
        }
        int size = command_list.size();
        for(int i = 0; i < size - 1; i++){
            copy(command_list[i], command_list.back());
        }
    }
    else if(strcmp(com1, "find") == 0){
        char path[100], file[100];
        sscanf(tmp, "find %s -name %s", path, file);
        find(path, file);
    }
}

// 命令提示
void print_prompt(){
    // 调用uname获取系统信息
    struct utsname buf;
    // 获取有关当前内核的名称和信息
    uname(&buf);
    // 通过用户的uid查找用户的passwd数据
    struct passwd* info = getpwuid(getuid());
    // 保存当前路径 
    char cwd[100];  
    char prompt[100];
    while(true){
        // 调用 getcwd 获取当前路径名，并存储在 cwd 指向的字符串
        getcwd(cwd, sizeof(cwd));
        // 输出用户名,系统名称,当前路径     
        sprintf(prompt, "<%s@%s:%s> ", info->pw_name,buf.sysname, cwd);
        // 从命令行读取一行输入，并且允许用户使用左右箭头进行编辑
        char* input = readline(prompt);
        // 可以纪录下我们之前输入过的命令，并使用上下箭头来获取
        add_history(input);
        execute(input);
        // 会申请一块新的内存，所以需要手动释放内存
        free(input);
    }
}