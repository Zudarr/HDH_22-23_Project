#include "syscall.h"
#define MAX_LENGTH 32

int main()
{
	int id;
	int fileSize;
	char content[MAX_LENGTH];
	int i = 0; // Index for loop

	id = Open("Hello.txt"); // Goi ham Open de mo file

	if (id != -1) // Check if it is valid or not
	{
		// Seek to the end of file to get size
		fileSize = Seek(-1, id);
		Close(id);
		
		id = Open("Hello.txt");
		Read(content, fileSize, id); // Read the file
		Close(id);


		PrintString(content); // Print out file content
		PrintChar('\n');
	}
	else
	{
		PrintString("Error!!\n\n");
	}
}