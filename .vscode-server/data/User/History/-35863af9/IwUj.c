#include "syscall.h"

int main()
{
    char s[255];
    PrintString("Nhap kich thuoc chuoi: ");
    PrintString("Nhap mot chuoi: ");
    ReadString(s, ReadNum());
    PrintString("Chuoi vua nhap la: ");
    PrintString(s);
    PrintString("\n");
}