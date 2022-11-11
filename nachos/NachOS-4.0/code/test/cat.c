#include "syscall.h"

int main()
{
    char *filename;
    int fileID;
    char temp;
    int size;

    PrintString("Enter file name: ");
    ReadString(filename, 33);

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