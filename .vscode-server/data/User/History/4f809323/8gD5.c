#include "syscall.h"

int main()
{
    char* filename1 = "Hello.txt";
    char* filename2 = "Goodbye.txt";
    int fileID1 = Open(filename1);
    int fileID2 = Open(filename2);
    char temp;
    int size;

    size = Seek(-1, fileID2); // Size of the file you want to copy
    Seek(0, fileID2);
    while (size > 0)
    {
        Read(&temp, 1, fileID2);
        Write(&temp, 1, fileID1);
        PrintString(&temp);
        size--;
    }
    Close(fileID1);
    Close(fileID2);
    Halt();
}