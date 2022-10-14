#include "syscall.h"
char a[255];
int main() {
    PrintString("String length: (<= 255): ");
    ReadString(a, 255);
    PrintString(a);
}
