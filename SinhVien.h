#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;

class SinhVien {
private:
	string fullName;
	string studentID;
	string dateOfBirth;
	float grade[3];			// grade[4] -> grade[3]
	string rank;

public:
	SinhVien();
	SinhVien(string fullName, string studentID, string dateOfBirth, float grade[]);
	SinhVien(string fullName, string studentID);
	SinhVien(string fullName);	// name -> fullName
	~SinhVien();				// add Destructor

	float stdAvg();
	SinhVien copy();
	SinhVien& operator=(const SinhVien& sv);
	void printSV();
	void inputSV();
	
	bool isBirthday(SinhVien sv);					// add check birthday
	void writeToFile(SinhVien sv, string file);		// add export to file

	friend class QLSinhVien;
};

class QLSinhVien {
private:
	vector <SinhVien> listSV;
	int size;
public:

	QLSinhVien();
	~QLSinhVien();						// add Destructor

	float mean();
	void lowerThanMean();				// add export to file
	void insertSV(SinhVien sv, int pos);
	void deleteSV(int pos);
	void classification();
	void printListSV();
	void inputListSV(int num);

	void printListBirthday();			// add list birthday
	void writeToFile(string file);		// add 
	void readFromFile(string file);		// add 
};