// exception.cc
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "main.h"
#include "syscall.h"
#include "ksyscall.h"
#include "synchconsole.h"

/* độ dài tối đa của một số int */
#define MAX_NUM_LENGTH 11

#define LF ((char)10)
#define CR ((char)13)
#define TAB ((char)9)
#define SPACE ((char)' ')
//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2.
//
// If you are handling a system call, don't forget to increment the pc
// before returning. (Or else you'll loop making the same system call forever!)
//
//	"which" is the kind of exception.  The list of possible exceptions
//	is in machine.h.
//----------------------------------------------------------------------

char *User2System(int virtAddr, int limit)
{
	int i; // index
	int oneChar;
	char *kernelBuf = NULL;
	kernelBuf = new char[limit + 1]; // need for terminal string
	if (kernelBuf == NULL)
		return kernelBuf;
	memset(kernelBuf, 0, limit + 1);
	// printf("\n Filename u2s:");
	for (i = 0; i < limit; i++)
	{
		kernel->machine->ReadMem(virtAddr + i, 1, &oneChar);
		kernelBuf[i] = (char)oneChar;
		// printf("%c",kernelBuf[i]);
		if (oneChar == 0)
			break;
	}
	return kernelBuf;
}

int System2User(int virtAddr, int len, char *buffer)
{
	if (len < 0)
		return -1;
	if (len == 0)
		return len;
	int i = 0;
	int oneChar = 0;
	do
	{
		oneChar = (int)buffer[i];
		kernel->machine->WriteMem(virtAddr + i, 1, oneChar);
		i++;
	} while (i < len && oneChar != 0);
	return i;
}

void IncreasePC() // goi ham nay cuoi cac syscall
{
	kernel->machine->WriteRegister(PrevPCReg, kernel->machine->ReadRegister(PCReg));
	kernel->machine->WriteRegister(PCReg, kernel->machine->ReadRegister(NextPCReg));
	kernel->machine->WriteRegister(NextPCReg, kernel->machine->ReadRegister(NextPCReg) + 4);
}

char isBlank(char c) { return c == LF || c == CR || c == TAB || c == SPACE; }

char _buffer[MAX_NUM_LENGTH + 2];

void readAllInt()
{
	char input = kernel->synchConsoleIn->GetChar();

	if (input == EOF)
	{
		DEBUG(dbgSys, "Unexpected end of file - number expected");
		return;
	}

	if (isBlank(input))
	{
		DEBUG(dbgSys, "Unexpected white-space - number expected");
		return;
	}

	int n = 0;

	while (!(isBlank(input) || input == EOF))
	{
		_buffer[n++] = input;
		if (n > MAX_NUM_LENGTH)
		{
			DEBUG(dbgSys, "Number is too long");
			return;
		}
		input = kernel->synchConsoleIn->GetChar();
	}
}

void ExceptionHandler(ExceptionType which)
{
	int type = kernel->machine->ReadRegister(2);

	DEBUG(dbgSys, "Received Exception " << which << " type: " << type << "\n");

	switch (which)
	{
	case PageFaultException:
		DEBUG('a', "\nNo valid translation found.");
		printf("\n\nNo valid translation found.");
		kernel->interrupt->Halt();
		break;
	case ReadOnlyException:
		DEBUG('a', "\nWrite attempted to page  marked \"read-only\".");
		printf("\n\nWrite attempted to page  marked \"read-only\".");
		kernel->interrupt->Halt();
		break;
	case BusErrorException:
		DEBUG('a', "\nTranslation resulted in an invalid physical address.");
		printf("\n\nTranslation resulted in an invalid physical address.");
		kernel->interrupt->Halt();
		break;
	case AddressErrorException:
		DEBUG('a', "\nUnaligned reference or one that was beyond the end of the address space.");
		printf("\n\nUnaligned reference or one that was beyond the end of the address space.");
		kernel->interrupt->Halt();
		break;
	case OverflowException:
		DEBUG('a', "\nInteger overflow in add or sum.");
		printf("\n\nInteger overflow in add or sum.");
		kernel->interrupt->Halt();
		break;
	case IllegalInstrException:
		DEBUG('a', "\nUnimplemented or reserved instr.");
		printf("\n\nInteger overflow in add or sum.");
		kernel->interrupt->Halt();
		break;
	case NumExceptionTypes:
		cerr << "Error " << which << " occurs\n";
		SysHalt();
		ASSERTNOTREACHED();
	case SyscallException:
		switch (type)
		{
		case SC_Halt:
		{
			DEBUG(dbgSys, "Shutdown, initiated by user program.\n");

			SysHalt();

			ASSERTNOTREACHED();
			break;
		}

		case SC_Add:
		{
			DEBUG(dbgSys, "Add " << kernel->machine->ReadRegister(4) << " + " << kernel->machine->ReadRegister(5) << "\n");

			/* Process SysAdd Systemcall*/
			int result;
			result = SysAdd(/* int op1 */ (int)kernel->machine->ReadRegister(4),
							/* int op2 */ (int)kernel->machine->ReadRegister(5));

			DEBUG(dbgSys, "Add returning with " << result << "\n");
			/* Prepare Result */
			kernel->machine->WriteRegister(2, (int)result);

			/* Modify return point */
			{
				/* set previous programm counter (debugging only)*/
				kernel->machine->WriteRegister(PrevPCReg, kernel->machine->ReadRegister(PCReg));

				/* set programm counter to next instruction (all Instructions are 4 byte wide)*/
				kernel->machine->WriteRegister(PCReg, kernel->machine->ReadRegister(PCReg) + 4);

				/* set next programm counter for brach execution */
				kernel->machine->WriteRegister(NextPCReg, kernel->machine->ReadRegister(PCReg) + 4);
			}

			return;

			ASSERTNOTREACHED();

			break;
		}

		case SC_ReadChar:
		{
			char input = kernel->synchConsoleIn->GetChar();
			kernel->machine->WriteRegister(2, (int)input);
			IncreasePC();
			ASSERTNOTREACHED();
			break;
		}

		case SC_PrintChar:
		{
			char output = (char)kernel->machine->ReadRegister(4); // Doc ki tu tu thanh ghi r4
			kernel->synchConsoleOut->PutChar(output);			  // In ky tu tu bien c, 1 byte
			IncreasePC();
			ASSERTNOTREACHED();
			break;
		}

		case SC_ReadNum:
		{
			// đọc số nguyên người dùng nhập vào
			readAllInt();

			bool isNegative = false;
			int result = 0;
			if (_buffer[0] == '-')
			{
				isNegative = true;
			}

			for (int i = 0; i <= strlen(_buffer); i++)
			{
				if (isNegative && i == 0)
					continue; // nếu là số âm thì bỏ qua ký tự đầu là '-'
				if (_buffer[i] == '\0')
					break;								  // nếu gặp kí tự null, thoát vòng lặp
				if (_buffer[i] < '0' || _buffer[i] > '9') // nếu gặp bất kỳ ký tự nào không là số nguyên thì ngừng
				{
					kernel->machine->WriteRegister(2, 0);
					IncreasePC();
					return; // chuỗi nhập vào không là số nguyên, trả về 0, return ngắt hàm
				}
				result = result * 10 + (int)(_buffer[i] - 48);
			}
			if (isNegative)
			{
				result *= -1;
			}

			kernel->machine->WriteRegister(2, result);
			IncreasePC();
			break;
		}

		default:
			cerr << "Unexpected system call " << type << "\n";
			break;
		}
		break;
	default:
		cerr << "Unexpected user mode exception" << (int)which << "\n";
		break;
	}
	ASSERTNOTREACHED();
}
