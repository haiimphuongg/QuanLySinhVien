#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SinhVien {
private:
	string fullName;
	string studentID;
	string dateOfBirth;
	float grade[4];
	string rank;

public:
	SinhVien();
	SinhVien(string fullName, string studentID, string dateOfBirth, float grade[]);
	SinhVien(string fullName, string studentID);
	SinhVien(string name);


	float stdAvg();
	SinhVien copy();
	SinhVien& operator=(const SinhVien& sv);
	void printSV();
	void inputSV();

	friend class QLSinhVien;

};

class QLSinhVien {
private:
	vector <SinhVien> listSV;
	int size;
public:
	
	QLSinhVien();
	float mean();
	void lowerThanMean();
	void insertSV(SinhVien sv, int pos);
	void deleteSV(int pos);
	void classification();
	void printListSV();
	void inputListSV(int num);

};