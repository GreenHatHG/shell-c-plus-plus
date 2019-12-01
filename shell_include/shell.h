#ifndef SHELL_H
#define SHELL_H

// 显示当前所在目录的路径名(绝对路径)
void pwd();

// 列出指定目录名中的所有目录及文件
void list(char* name);

// 改变当前工作目录
void cd(char* path);

// 新建目录
void mkdir(char* path);

// 删除目录
void rmdir(char* path);

// 重命名一个文件或目录
void myrename(char* oldpath, char* newpath);

// 复制一个已存在的文件
void copy(char* oldfile, char* newfile);

// 在指定的目录及其子目录中查找指定的文件，并输出查找到的文件的绝对路径
void find(char* path, char* file);

//  用于输出提示符
void print_prompt();

// void scan_command(char *command);
#endif