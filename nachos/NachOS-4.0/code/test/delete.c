#include "syscall.h"

int main()
{
    int res; 

    res = Remove("Hello.txt");

    PrintString("Remove file return ");
    PrintNum(res);
    PrintString(".\n");
}