#ifndef SHELL_H
#define SHELL_H

// 显示当前所在目录的路径名(绝对路径)
void pwd();

// 列出指定目录名中的所有目录及文件
void list();

// 改变当前工作目录
void cd();

// 新建目录
void mkdir();

// 删除目录
void rmdir();

// 重命名一个文件或目录
void rename();

// 复制一个已存在的文件
void copy();

// 在指定的目录及其子目录中查找指定的文件，并输出查找到的文件的绝对路径
void find();
#endif