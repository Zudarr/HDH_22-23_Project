#include "syscall.h"
int result;
int main()
{
    result = RandomNum();
    PrintString("So ngau nhien la: ");
    PrintNum(result);
    PrintString("\n");
}
