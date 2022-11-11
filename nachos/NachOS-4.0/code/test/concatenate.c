#include "syscall.h"

int main()
{
    char *filename1;
    char *filename2;
    char temp;

    PrintString("Enter the name of the first file: ");
    ReadString(filename1, 33);
    PrintString("Enter the name of the second file: ");
    ReadString(filename2, 33);

    int fileID1 = Open(filename1);
    int fileID2 = Open(filename2);

    int size = Seek(-1, fileID2); // size of data to append from file2 to file1

    Seek(0, fileID2);  // start of file2
    Seek(-1, fileID1); // end of file1

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