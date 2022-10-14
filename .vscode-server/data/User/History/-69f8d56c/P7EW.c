#include "syscall.h"

int
main()
{
	PrintString("\n\t\t\t-----Cac thanh vien nhom-----\n");
	PrintString("\t\tPham Phuoc Nguyen - 19120311\n");
	PrintString("\t\tNguyen Doan Phuc - 19120\n");
	PrintString("----------------------------------------\n");

	PrintString("\n\t\t\t-----Chuong trinh sort-----\n");
	PrintString("\t\t-Tao mang gom 1 -> 100 phan tu\n");
	PrintString("\t\t-Moi nguoi dung nhap so phan tu va lan luot nhap cac phan tu\n");
	PrintString("\t\t-Moi nguoi dung chon loai sap xep (tang dan / giam dan)\n");
	PrintString("\t\t-Su dung thuat toan Bubble Sort de sap xep mang\n");
	PrintString("\t\t-Hien thi lai mang sau khi da sap xep\n");

	PrintString("\n\t\t\t-----Chuong trinh ascii-----\n");
	PrintString("\t\t-Dung vong lap de in cac phan tu trong bang ma ascii (tu phan tu thu 32 den 127)\n");
	PrintString("\t\t-Voi moi phan tu lan luot xuat ra cac thong tin sau:\n");
	PrintString("\t\t\t+Dung ham PrintInt() de xuat gia tri o he thap phan\n");
	PrintString("\t\t\t+Dung ham PrintString() de xuat chuoi \" - \"\n");
	PrintString("\t\t\t+Dung ham PrintChar() de xuat ky tu tuong ung\n");
	PrintString("\t\t\t+Dung ham PrintString() de xuat ky tu xuong dong\n");
}
