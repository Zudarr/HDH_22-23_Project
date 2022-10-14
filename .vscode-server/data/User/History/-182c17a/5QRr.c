#include "syscall.h"

int main()
{
    char c;
    PrintString("Nhap mot ky tu: ");
    c = ReadChar();
    PrintString("Ky tu vua nhap la: ");
    PrintChar(c);
    PrintString("\n");
}