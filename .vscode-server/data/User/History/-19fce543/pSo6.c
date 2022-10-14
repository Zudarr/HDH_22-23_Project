#include "syscall.h"
#define SIZE (100)

int main()
{
    int n, a[SIZE + 1], order, temp, i, j;
    do
    {
        PrintString("Nhap so luong phan tu n (0 <= n <= 100): ");
        n = ReadNum();
        if (n < 0 || n > 100)
            PrintString("So luong khong hop le, moi nhap lai\n");
    } while (n < 0 || n > 100);

    for (i = 0; i < n; i++)
    {
        PrintString("Nhap phan tu thu ");
        PrintNum(i + 1);
        PrintString(": ");
        a[i] = ReadNum();
    }

    do
    {
        PrintString("Nhap loai sap xep (1: tang dan, 2: giam dan): ");
        order = ReadNum();
        if (order != 1 && order != 2)
            PrintString("Wrong input, please try again\n");
    } while (order != 1 && order != 2);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (order == 1)
            {
                if (a[j] > a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
            else if (order == 2)
            {
                if (a[j] < a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    PrintString("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        PrintNum(a[i]);
        PrintChar(' ');
    }
}
