#include "syscall.h"
#define MAX_LENGTH 32

int main()
{
	char *fileName = "Hello.txt";
	int id;
	int fileSize;
	char content;
	int i = 0; // Index for loop

	id = Open(fileName); // Goi ham Open de mo file

	if (id != -1) // Check if it is valid or not
	{
		// Seek to the end of file to get size
		fileSize = Seek(-1, id);
		Close(id);

		id = Open("Hello.txt");
		while (fileSize > 0)
		{
			Read(&content, 1, id); // Read the file
			PrintString(&content);
			fileSize--;
		}

		Close(id);
	}
	else
	{
		PrintString("Error!!\n\n");
	}
}