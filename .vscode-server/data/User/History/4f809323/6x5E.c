#include "syscall.h"
#define MAX_LENGTH 32

int main()
{
    int srcId;
    int destId;

    int fileSize;
    int i = 0; // Index for loop
    char c;

    char *sourceFile = "Hello.txt";
    char *destFile = "Goodbye.txt";

    srcId = Open(sourceFile);

    if (srcId != -1) // check if it is valid or not
    {
        destId = Open(destFile);
        if (destId != -1) // check if it is valid or not
        {
            fileSize = Seek(-1, srcId);

            Close(srcId);
            Close(destId);

            srcId = Open(sourceFile);
            destId = Open(destFile);


            for (; i < fileSize; i++)
            {
                Read(&c, 1, srcId);
                Write(&c, 1, destId);
            }

            PrintString("Successful!\n\n");
            Close(destId); //
        }
        else
        {
            PrintString("Error!!!\n\n");
        }

        Close(srcId); //
    }
    else
    {
        PrintString("Failed to open file!!\n");
    }
}