#include "SinhVien.h"

SinhVien::SinhVien()
{
	fullName = "";
	studentID = "";
	dateOfBirth = "";
	grade[0] = grade[1] = grade[2] = 0;
}

SinhVien::SinhVien(string name, string ID, string date, float mark[])
{
	fullName = name;
	studentID = ID;
	dateOfBirth = date;
	grade[0] = mark[0];
	grade[1] = mark[1];
	grade[2] = mark[2];
}

SinhVien::SinhVien(string name, string ID)
{
	fullName = name;
	studentID = ID;
	dateOfBirth = "";
	grade[0] = grade[1] = grade[2] = 0;
}

SinhVien::SinhVien(string name)
{
	fullName = name;
	studentID = "";
	dateOfBirth = "";
	grade[0] = grade[1] = grade[2] = 0;
}

float SinhVien::stdAvg()
{
	return (grade[0] * 0.25 + grade[1] * 0.25 + grade[2] * 0.5);
}

SinhVien SinhVien::copy()
{
	SinhVien newSV;
	newSV.fullName = fullName;
	newSV.dateOfBirth = dateOfBirth;
	newSV.studentID = studentID;
	newSV.grade[0] = grade[0];
	newSV.grade[1] = grade[1];
	newSV.grade[2] = grade[2];

	return newSV;
}

SinhVien& SinhVien::operator=(const SinhVien& sv)
{
	if (this == &sv)
	{
		return *this;
	}

	
	fullName = sv.fullName;
	studentID = sv.studentID;
	dateOfBirth = sv.dateOfBirth;
	grade[0] = sv.grade[0];
	grade[1] = sv.grade[1];
	grade[2] = sv.grade[2];
		
	return *this;
}