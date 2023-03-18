#pragma once
#include <iostream>
using namespace std;

class SinhVien {
private:
	string fullName;
	string studentID;
	string dateOfBirth;
	float grade[4];

public:
	SinhVien();
	SinhVien(string fullName, string studentID, string dateOfBirth, float grade[]);
	SinhVien(string fullName, string studentID);
	SinhVien(string name);


	float stdAvg();
	SinhVien copy();
	SinhVien& operator=(const SinhVien& sv);

};