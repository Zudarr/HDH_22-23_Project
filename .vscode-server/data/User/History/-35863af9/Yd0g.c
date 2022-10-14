#include "syscall.h"
char a[256];
int main() {
    PrintString("String length: (<= 255):\n");
    ReadString(a, 255);
    PrintString(a);
}
