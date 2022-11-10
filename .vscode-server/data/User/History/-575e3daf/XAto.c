#include "syscall.h"

int main()
{
    int fileID1;
    int fileID2;

    char temp;
    int size;
    
    fileID1 = Open("Hello.txt");
    fileID2 = Open("Hello.txt");

    size = Seek(-1, fileID2);   // size of data to append from file2 to file1

    Seek(0, fileID2);   // start of file2
    Seek(-1, fileID1);  // end of file1

    while (size > 0)
    {
        Read(&temp, 1, fileID2);
        Write(&temp, 1, fileID1);
        PrintString(&temp);
        size--;
    }
    Close(fileID1);
    Close(fileID2);
}