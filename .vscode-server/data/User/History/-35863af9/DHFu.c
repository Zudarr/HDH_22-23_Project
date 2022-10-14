#include "syscall.h"
char s[255];
int main()
{
    PrintString("Nhap mot chuoi: ");
    ReadString(s, 255);
    PrintString("Chuoi vua nhap la: ");
    PrintString(s);
    PrintString("\n");
}
