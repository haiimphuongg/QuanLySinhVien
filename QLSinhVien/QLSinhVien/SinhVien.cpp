#include "SinhVien.h"

SinhVien::SinhVien() {
	mFullName = new char[50];
	mStudentID = new char[20];
	mDateOfBirth = new char[20];
	mGrade[0] = 0;
	mGrade[1] = 0;
	mGrade[2] = 0;
	mRank = new char[20];
}

SinhVien::~SinhVien() {
	if (mFullName != NULL)
	{
		delete[]mFullName;
	}
	if (mStudentID != NULL)
	{
		delete[] mStudentID;
	}
	if (mDateOfBirth != NULL)
	{
		delete[](mDateOfBirth);
	}
	if (mRank != NULL)
	{
		delete[](mRank);
	}

}

SinhVien::SinhVien(const SinhVien& sv)
{
	delete[](mFullName);
	delete[](mStudentID);
	delete[](mDateOfBirth);
	delete[](mRank);

	mFullName = new char[strlen(sv.mFullName) + 1];
	mStudentID = new char[strlen(sv.mStudentID) + 1];
	mDateOfBirth = new char[strlen(sv.mDateOfBirth) + 1];
	mRank = new char[strlen(sv.mRank) + 1];

	for (int i = 0; i < strlen(mFullName); i++)
	{
		mFullName[i] = sv.mFullName[i];
	}
	for (int i = 0; i < strlen(mStudentID); i++)
	{
		mStudentID[i] = sv.mStudentID[i];
	}
	for (int i = 0; i < strlen(mDateOfBirth); i++)
	{
		mDateOfBirth[i] = sv.mDateOfBirth[i];
	}
	for (int i = 0; i < strlen(mFullName); i++)
	{
		mRank[i] = sv.mRank[i];
	}
	mGrade[0] = sv.mGrade[0];
	mGrade[1] = sv.mGrade[1];
	mGrade[2] = sv.mGrade[2];
}

float SinhVien::stdAvg()
{
	return (mGrade[0] * 0.25 + mGrade[1] * 0.25 + mGrade[2] * 0.5);

}

SinhVien& SinhVien:: operator=(const SinhVien& sv)
{
	if (this == &sv)
	{
		return *this;
	}

	else
	{
		delete[](mFullName);
		delete[](mStudentID);
		delete[](mDateOfBirth);
		delete[](mRank);

		mFullName = new char[strlen(sv.mFullName) + 1];
		mStudentID = new char[strlen(sv.mStudentID) + 1];
		mDateOfBirth = new char[strlen(sv.mDateOfBirth) + 1];
		mRank = new char[strlen(sv.mRank) + 1];

		for (int i = 0; i < strlen(mFullName); i++)
		{
			mFullName[i] = sv.mFullName[i];
		}
		for (int i = 0; i < strlen(mStudentID); i++)
		{
			mStudentID[i] = sv.mStudentID[i];
		}
		for (int i = 0; i < strlen(mDateOfBirth); i++)
		{
			mDateOfBirth[i] = sv.mDateOfBirth[i];
		}
		for (int i = 0; i < strlen(mFullName); i++)
		{
			mRank[i] = sv.mRank[i];
		}
		mGrade[0] = sv.mGrade[0];
		mGrade[1] = sv.mGrade[1];
		mGrade[2] = sv.mGrade[2];
	}
}

void SinhVien::inputSV()
{
	cout << "Nhap ho va ten: ";
	cin.getline(mFullName, 50);

	cout << "Nhap MSSV: ";
	cin.getline(mStudentID, 50);
	
	cout << "Nhap ngay thang nam sinh (BAT BUOC dinh dang dd/mm/yyyy): ";
	cin.getline(mDateOfBirth, 50);

	cout << "Nhap diem bai tap: ";
	cin >> mGrade[0];

	cout << "Nhap diem giua ki: ";
	cin >> mGrade[1];

	cout << "Nhap diem cuoi ki: ";
	cin >> mGrade[2];

	cin.ignore();
}

istream& operator>>(istream& in, SinhVien& sv)
{
	sv.inputSV();
	return in;
}
void SinhVien::printSV()
{
	cout << mFullName << " - " << mStudentID << " - " << mDateOfBirth << " - " << mGrade[0] << " - " << mGrade[1] << " - " << mGrade[2];
	if (mRank[0] == 'G' || mRank[0] == 'K' || mRank[0] == 'T' || mRank[0] == 'Y') cout << " - " << mRank << endl;
	else cout << endl;
}

ostream& operator<<(ostream& out, SinhVien& sv)
{
	sv.printSV();
	return out;
}


bool SinhVien::isBirthday(int curDay, int curMonth)
{
	int start = 0;
	int end = 0;
	int i = 0;
	string day;
	string month;
	string year;
	int count = 0;
	while (i < strlen(mDateOfBirth))
	{
		if (mDateOfBirth[i] != '/')
		{
			if (count == 0)	day += mDateOfBirth[i];
			if (count == 1) month += mDateOfBirth[i];
			if (count == 2) year += mDateOfBirth[i];
		}

		else {
			count++;
		}
		i++;
	}
	if (curDay == stoi(day) && curMonth == stoi(month))
		return true;

	return false;
}

