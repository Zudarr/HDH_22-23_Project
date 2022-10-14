#include "syscall.h"

int main()
{
    char s[255];
    int size;
    PrintString("Nhap kich thuoc chuoi: ");
    size = ReadNum();
    PrintString("Nhap mot chuoi: ");
    ReadString(s, ReadNum());
    PrintString("Chuoi vua nhap la: ");
    PrintString(s);
    PrintString("\n");
}
