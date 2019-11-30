#include <iostream>
#include "shell.h"
using namespace std;

int main()
{
    // pwd();
    // list();
    // cd();
    // mymkdir();
    // rmdir();
    // rename();
    // copy();
    // find();
    print_prompt();
    char command[100];
    scan_command(command); 
    return 0;
}