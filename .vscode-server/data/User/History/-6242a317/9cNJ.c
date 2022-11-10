#include "syscall.h"

int main()
{
    char *fileName = "Hello.txt";
    int result;
    result = Create(fileName);
    if (result == -1)
    {
        PrintString("Error");
    }
    else
    {
        PrintString("Create file success");
    }
    return 0;
}