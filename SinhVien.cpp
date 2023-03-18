#include "SinhVien.h"

SinhVien::SinhVien()
{
	fullName = "";
	studentID = "";
	dateOfBirth = "";
	grade[0] = grade[1] = grade[2] = 0;
	rank = "";
}

SinhVien::SinhVien(string name, string ID, string date, float mark[])
{
	fullName = name;
	studentID = ID;
	dateOfBirth = date;
	grade[0] = mark[0];
	grade[1] = mark[1];
	grade[2] = mark[2];
	rank = "";
}

SinhVien::SinhVien(string name, string ID)
{
	fullName = name;
	studentID = ID;
	dateOfBirth = "";
	grade[0] = grade[1] = grade[2] = 0;
	rank = "";
}

SinhVien::SinhVien(string name)
{
	fullName = name;
	studentID = "";
	dateOfBirth = "";
	grade[0] = grade[1] = grade[2] = 0;
	rank = "";
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
	newSV.rank = rank;
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
	rank = sv.rank;
	return *this;
}

void SinhVien::printSV()
{
	cout << fullName << " / " << studentID << " / " << dateOfBirth << " / " << grade[0] << " / " << grade[1] << " / " << grade[2] << " / " << this->stdAvg() << " / " << rank << endl;
}

void SinhVien::inputSV()
{
	string day;
	string month;
	string year;
	cout << "Nhap ho va ten: ";
	getline(cin, fullName);
	cout << "Nhap MSSV: ";
	getline(cin, studentID);
	cout << "Nhap ngay sinh: ";
	cin >> day;
	cout << "Nhap thang sinh: ";
	cin >> month;
	cout << "Nhap nam sinh: ";
	cin >> year;
	dateOfBirth = day + "/" + month + "/" + year;
	cout << "Nhap diem bai tap: ";
	cin >> grade[0];
	cout << "Nhap diem giua ki: ";
	cin >> grade[1];
	cout << "Nhap diem cuoi ki: ";
	cin >> grade[2];
	cin.ignore();
}

QLSinhVien::QLSinhVien()
{
	listSV.resize(0);
	size = 0;
}

float QLSinhVien::mean()
{
	float sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += listSV[i].stdAvg();
	}
	return ((1.0*sum) / size);
}

void QLSinhVien::lowerThanMean()
{
	for (int i = 0; i < size; i++)
	{
		if (listSV[i].stdAvg() < this->mean())
			listSV[i].printSV();
	}
}

void QLSinhVien::insertSV(SinhVien sv, int pos)
{
	listSV.insert(listSV.begin() + pos, sv);
	size++;
}

void QLSinhVien::deleteSV(int pos)
{
	listSV.erase(listSV.begin() + pos);
	size--;
}

void QLSinhVien::classification() 
{
	for (int i = 0; i < size; i++)
	{
		if (listSV[i].stdAvg() >= 8)
		{
			listSV[i].rank = "Gioi";
		}
		else if (listSV[i].stdAvg() >= 6.5)
		{
			listSV[i].rank = "Kha";
		}
		else if (listSV[i].stdAvg() >= 5)
		{
			listSV[i].rank = "Trung binh";
		}
		else
			listSV[i].rank = "Yeu";
	}
}

void QLSinhVien::printListSV()
{
	for (int i = 0; i < size; i++)
	{
		listSV[i].printSV();
	}
}

void QLSinhVien::inputListSV(int num)
{
	SinhVien temp;
	for (int i = 0; i < num; i++)
	{
		temp.inputSV();
		insertSV(temp, size);
	}
}