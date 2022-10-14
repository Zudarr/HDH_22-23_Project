#include "syscall.h"
//chương trình in ra bảng mã ascii

int main() {
	int i = 32;
    for (i; i < 127; i++) 
    {
        PrintNum(i); //in giá trị hệ thập phân
        PrintString(" - ");
        PrintChar(i); //in ký tự tương ứng
        PrintString("\n");
    }
}