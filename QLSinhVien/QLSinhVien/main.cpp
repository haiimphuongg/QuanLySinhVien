#define _CRT_SECURE_NO_DEPRECATE

#include "SinhVien.h";
#include "QLSinhVien.h";

int main()
{
	QLSinhVien myList(100);

	myList.inputListSV(2);
	myList.printListSV();
	
}