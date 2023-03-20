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

SinhVien::~SinhVien() 
{
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

bool SinhVien::isBirthday(SinhVien sv) 
{
	time_t t = time(0);
	tm* now = localtime(&t);

	char buffer[5];
	strftime(buffer, 5, "%d%m", now);

	string s = buffer;
	string curDay = s.substr(0, 2);
	string curMonth = s.substr(2, 2);

	int start = 0;
	int end = dateOfBirth.find('/', 0);
	string day = dateOfBirth.substr(start, end - start);

	start = end + 1;
	end = dateOfBirth.find('/', 0);
	string month = dateOfBirth.substr(start, end - start);

	if (stoi(curDay) == stoi(day) && stoi(curMonth) == stoi(month))
		return true;

	return false;
}

void SinhVien::writeToFile(SinhVien sv, string file) 
{
	fstream fout;

	fout.open(file, ios::out | ios::app);

	fout << sv.fullName << ","
		<< sv.studentID << ","
		<< sv.dateOfBirth << ","
		<< sv.grade[0] << ","
		<< sv.grade[1] << ","
		<< sv.grade[2] << endl;

	fout.close();

	return;
}

QLSinhVien::QLSinhVien()
{
	listSV.resize(0);
	size = 0;
}

QLSinhVien::~QLSinhVien()
{
}

float QLSinhVien::mean()
{
	float sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += listSV[i].stdAvg();
	}
	return ((1.0 * sum) / size);
}

void QLSinhVien::lowerThanMean()
{
	for (int i = 0; i < size; i++)
	{
		if (listSV[i].stdAvg() < this->mean()) {
			listSV[i].printSV();
			listSV[i].writeToFile(listSV[i], "LowerThanMean.csv");
		}

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
		cout << "\n";
	}
}

void QLSinhVien::printListBirthday() 
{
	for (int i = 0; i < size; i++)
	{
		if(listSV[i].isBirthday(listSV[i]))
			listSV[i].printSV();
	}
}

void QLSinhVien::writeToFile(string file) 
{
	for (int i = 0; i < size; i++)
		listSV[i].writeToFile(listSV[i], file);

	return;
}

void QLSinhVien::readFromFile(string file) 
{
	fstream fin;

	fin.open(file, ios::in);

	string temp = "";
	vector<string> info;
	int cnt = 0;

	SinhVien sv;

	while (getline(fin, temp))
	{
		int start = 0;
		int end = temp.find(',', start); // string.find('c', pos_start) -> tim vi tri cua 'c' -> -1 neu khong co 'c'

		info.clear();

		while (end != -1)
		{
			info.push_back(temp.substr(start, end - start)); // string.substr(pos_start, size_substr);
			start = end + 1;
			end = temp.find(',', start);
		}

		info.push_back(temp.substr(start, end - start));

		sv.fullName = info[0];
		sv.studentID = info[1];
		sv.dateOfBirth = info[2];
		sv.grade[0] = stof(info[3]);
		sv.grade[1] = stof(info[4]);
		sv.grade[2] = stof(info[5]);

		insertSV(sv, size);
	}

	return;
}