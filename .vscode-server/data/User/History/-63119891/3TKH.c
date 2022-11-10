#include "syscall.h"
#define MAX_LENGTH 32

int main()
{
	int id;
	int fileSize;
	char content;
	int i = 0; // Index for loop

	id = Open("Hello.txt"); // Goi ham Open de mo file

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