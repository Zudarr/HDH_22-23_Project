#include "syscall.h"
#define MAX_LENGTH 32

int main()
{
    int fileID;
    char temp;
    int size;

    fileID = Open("Hello.txt");
    size = Seek(-1, fileID);

    Seek(0, fileID);
    while (size > 0)
    {
        Read(&temp, 1, fileID);
        PrintString(&temp);
        size--;
    }
    Close(fileID);
}