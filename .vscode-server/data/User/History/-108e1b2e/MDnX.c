#include "syscall.h"
int n;
int main()
{
    PrintString("Nhap mot so nguyen: ");
    n = ReadInt();
    PrintString("So vua nhap la: ");
    PrintInt(n);
    PrintString("\n");
}
