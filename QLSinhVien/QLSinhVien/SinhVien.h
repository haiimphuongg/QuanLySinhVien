#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;


class SinhVien
{
public:
	SinhVien();
	~SinhVien();
	SinhVien(const SinhVien& sv);
	float stdAvg();
	SinhVien& operator=(const SinhVien& sv);
	void inputSV();
	void printSV();
	bool isBirthday();
	void writeToFile(SinhVien sv, char* file);
	friend class QLSinhVien;

private:
	char* mFullName;
	char* mStudentID;
	char* mDateOfBirth;
	float mGrade[3];
	char* mRank;

};

