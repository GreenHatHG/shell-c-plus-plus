# 概述

## 实验环境

- 系统：Linux 系统（发行版为 Arch Linux）
-  内核：x86_64 Linux 5.3.13-arch1-1
-  G++ / GCC 版本：9.2.0
-  实现语言：C++

## 特点

程序的主要功能特点是：
1. 显示用户名，系统名称，用户当前目录为提示符
2. 可以使用上下箭头来获取历史记录
3. 可以使用 tab 补全文件名
4. 尽量还原原生 linux 体验

# 命令

| 命令                                     | 说明                                                         |
| ---------------------------------------- | ------------------------------------------------------------ |
| pwd                                      | 显示当前所在目录的路径名                                     |
| list  <目录名>                           | 列出指定目录名中的所有目录及文件                             |
| cd  <目录名或路径>                       | 改变当前工作目录                                             |
| mkdir  <目录名>                          | 新建目录（可以批量创建，不能递归创建目录）                   |
| rmdir  <目录名>                          | 删除目录（可以批量删除，可以删除非空目录）                   |
| exit                                     | 退出命令解释程序                                             |
| rename  <旧文件名> <新文件名>            | 重命名一个文件或目录                                         |
| copy <已存在的文件名> <副本文件名或路径> | 复制一个已存在的文件到新的文件，或者到文件夹（可以批量复制） |
| find <目录> -name <待查找的文件名>       | 在指定的目录及其子目录中查找指定的文件，并输出查找到的文件的绝对路径（需要输入的目录是绝对路径） |

# 运行方法

需在装有 g++和 gcc 的 linux 平台运行
在源代码目录下执行：

```bash
$ git clone https://github.com/GreenHatHG/shell-c-plus-plus.git
$ cd shell-c-plus-plus
$ g++ src/main.cpp shell_include/*.cpp -I ./shell_include -o out/shell-c++ -lreadline && ./out/shell-c++
```

最终的可执行文件在当前目录的 out 目录下，文件名为 shell-c++

# 截图

## 运行

这里使用了g++编译连接，需要指定cpp文件位置还有自定义头文件的位置

![](https://i.loli.net/2019/12/02/Zj8G4gdfzBhnQrb.png)

## pwd

显示当前所在目录的路径名，可以看到提示符那里和用户所在路径是一样的

![](https://i.loli.net/2019/12/02/WBveKcikV9CAS4w.png)

## list

列出指定目录名中的所有目录及文件，我们可以直接使用list显示当前目录内容，
也可以指定文件夹，total 为文件数

![](https://i.loli.net/2019/12/02/5pRuHvwTDWClI6J.png)

## cd

进入当前文件夹的 out 文件夹，同时提示符那里的用户目录实时改变

![](https://i.loli.net/2019/12/02/7UYzdAsSQ8g2tmJ.png)

## mkdir

使用 mkdir 批量创建文件夹

![](https://i.loli.net/2019/12/02/NHF4lcjoLRSeM62.png)

##  rmdir

使用 rmdir 批量删除文件夹

![](https://i.loli.net/2019/12/02/Aq8veQpS1TotaYb.png)

删除非空文件夹

![](https://i.loli.net/2019/12/02/2hYTybpV85luxkq.png)

## rename

使用 rename 重命名 test 文件夹名字为 newtest

![](https://i.loli.net/2019/12/02/3WZFTcGykgKXVDP.png)

使用 rename 重命名 file.txt 文件名字为 newfile.txt

![](https://i.loli.net/2019/12/02/hpT3rHEvzas52wn.png)

## copy

批量复制一个已存在的文件到文件夹

![](https://i.loli.net/2019/12/02/9Yjl4pWDHtQyS8g.png)

复制一个已存在的文件到新的文件

![](https://i.loli.net/2019/12/02/VWy5jxlb698TEis.png)

## find

查找/home/cc 目录下所有名字为 list.cpp 的文件，并输出绝对路径

![](https://i.loli.net/2019/12/02/e2giYO4mlPVSHRz.png)

## exit

![](https://i.loli.net/2019/12/02/HzOCpVBFhjveRAx.png)