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
		fileSize = Seek(-1, id);
		i = 0;
		
		Seek(0, id);
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