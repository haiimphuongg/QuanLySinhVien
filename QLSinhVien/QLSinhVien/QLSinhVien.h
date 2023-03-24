#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include "SinhVien.h";


class QLSinhVien
{
public:
	QLSinhVien();
	QLSinhVien(int);
	~QLSinhVien();
	QLSinhVien(const QLSinhVien& list);


	float mean();
	void lowerThanMean();				// add export to file
	void insertSV(SinhVien&);
	void deleteSV(int pos);
	void classification();
	void printListSV();
	void inputListSV(int num);
	void printListBirthday();			// add list birthday
	void writeToFile(string file);		// add 
	void readFromFile(string file);


private:
	SinhVien* listSV;
	int mSize;
	int mCapacity;
};
 