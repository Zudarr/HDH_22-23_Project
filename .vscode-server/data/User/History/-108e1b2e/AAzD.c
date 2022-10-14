#include "syscall.h"
int n;
int main()
{
    PrintString("Nhap mot so nguyen: ");
    n = ReadNum();
    PrintString("So vua nhap la: ");
    PrintNum(n);
    PrintString("\n");
}
