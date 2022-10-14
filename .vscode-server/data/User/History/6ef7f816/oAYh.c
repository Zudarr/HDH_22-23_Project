#include "syscall.h"

int main() {
    int result;
    result = RandomNum();
    PrintString("So ngau nhien la: ");
    PrintNum(result);
    PrintString("\n");
}
