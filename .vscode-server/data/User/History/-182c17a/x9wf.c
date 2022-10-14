#include "syscall.h"
char c;
int main()
{
    PrintString("Nhap mot ky tu: ");
    c = ReadChar();
    PrintString("Ky tu vua nhap la: ");
    PrintChar(c);
    PrintString("\n");
}