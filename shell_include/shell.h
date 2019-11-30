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
#endif