#include "syscall.h"

int main()
{
    char* filename = "Hello.txt";
    int fileID;
    char temp;
    int size;

    fileID = Open(filename);
    size = Seek(-1, fileID);

    Seek(0, fileID);
    while (size > 0)
    {
        Read(&temp, 1, fileID);
        PrintString(&temp);
        size--;
    }
    Close(fileID);
    PrintString("\n");
}