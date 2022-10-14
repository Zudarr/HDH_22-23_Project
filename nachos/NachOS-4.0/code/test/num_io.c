#include "syscall.h"

int main()
{
    int n;
    PrintString("Nhap mot so nguyen: ");
    n = ReadNum();
    PrintString("So vua nhap la: ");
    PrintNum(n);
    PrintString("\n");
}
