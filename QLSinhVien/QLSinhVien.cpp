#include "QLSinhVien.h";

QLSinhVien::QLSinhVien()
{
	listSV = new SinhVien[100];
	mSize = 0;
	mCapacity = 100;
}
QLSinhVien::QLSinhVien(int capacity)
{
	listSV = new SinhVien[capacity + 1];
	mSize = 0;
	mCapacity = capacity;
}

QLSinhVien::QLSinhVien(const QLSinhVien& list)
{
	if (listSV != NULL) delete[]listSV;

	listSV = new SinhVien[list.mCapacity];
	mSize = list.mSize;
	mCapacity = list.mCapacity;
	
	for (int i = 0; i < mSize; i++)
	{
		listSV[i] = list.listSV[i];
	}

}
QLSinhVien::~QLSinhVien()
{
	if (listSV != NULL) delete[]listSV;
}

float QLSinhVien::mean()
{
	float sum = 0;
	for (int i = 0; i < mSize; i++)
	{
		sum += listSV[i].stdAvg();
	}
	return ((1.0 * sum) / mSize);
}

void QLSinhVien::lowerThanMean()
{
	fstream fout;
	fout.open("LowerThanMean.csv", ios::out);
	for (int i = 0; i < mSize; i++)
	{
		if (listSV[i].stdAvg() < this->mean()) {
			listSV[i].printSV();
			fout << listSV[i].mFullName << ","
				<< listSV[i].mStudentID << ","
				<< listSV[i].mDateOfBirth << ","
				<< listSV[i].mGrade[0] << ","
				<< listSV[i].mGrade[1] << ","
				<< listSV[i].mGrade[2] << endl;
		}
	}
}


void QLSinhVien::insertSV(SinhVien& insertedSV)
{
	if (mSize >= mCapacity)
	{
		int num; 
		cout << "Danh sach da day, ban co muon tiep tuc them sinh vien?";
		cout << "\nNhan 1 de them, 0 de ket thuc.\n";
		cin >> num;
		
		if (num == 1)
		{
			mCapacity = mCapacity * 2;
			SinhVien* newListSV = new SinhVien[mCapacity];

			for (int i = 0; i < mSize; i++)
			{
				newListSV[i] = listSV[i];
			}

			delete[] listSV;
			listSV = newListSV;
		}
	}

	listSV[mSize] = insertedSV;
	mSize ++;
}

void QLSinhVien::classification()
{
	for (int i = 0; i < mSize; i++)
	{
		if (listSV[i].stdAvg() >= 8)
		{
			strcpy(listSV[i].mRank, "Gioi");
		}
		else if (listSV[i].stdAvg() >= 6.5)
		{
			strcpy(listSV[i].mRank, "Kha");
		}
		else if (listSV[i].stdAvg() >= 5)
		{
			strcpy(listSV[i].mRank, "Trung binh");
		}
		else
			strcpy(listSV[i].mRank, "Yeu");
	}
}
void QLSinhVien::printListSV()
{
	for (int i = 0; i < mSize; i++)
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
		insertSV(temp);
		cout << "\n";
	}
}

void QLSinhVien::printListBirthday()
{
	for (int i = 0; i < mSize; i++)
	{
		if (listSV[i].isBirthday())
			listSV[i].printSV();
	}
}

void QLSinhVien::writeToFile(string file)
{
	fstream fout;
	fout.open(file, ios::out);
	for (int i = 0; i < mSize; i++)
	{
		fout << listSV[i].mFullName << ","
			<< listSV[i].mStudentID << ","
			<< listSV[i].mDateOfBirth << ","
			<< listSV[i].mGrade[0] << ","
			<< listSV[i].mGrade[1] << ","
			<< listSV[i].mGrade[2];
		if (i + 1 != mSize) fout << endl;
		
	}
	fout.close();
	return;
}

void QLSinhVien::readFromFile(string file)
{
	if (listSV != NULL)
	{
		delete[] listSV;
		listSV = new SinhVien[100];
		mSize = 0;
	}

	fstream fin;
	fin.open(file, ios::in);

	int start = 0;
	int end = 0;
	int count = 0;
	int cur = 0;
	int length = 0;
	int i = 0; 
	
	string tempStr;
	while (!fin.eof())
	{
		mSize++;
		char* temp = new char[200];
		fin.getline(temp, 100);
		i = 0;
		tempStr = "";
		length = strlen(temp);
		while (i < length)
		{
			if (temp[i] != ',')
			{
				tempStr += temp[i];
			}
			
			else
			{
				count++;
				if (count == 1)
				{
					strcpy(listSV[cur].mFullName, tempStr.c_str());
				}
				else if (count == 2)
				{
					strcpy(listSV[cur].mStudentID, tempStr.c_str());
				}
				else if (count == 3)
				{
					strcpy(listSV[cur].mDateOfBirth, tempStr.c_str());
				}
				else if (count == 4)
				{
					listSV[cur].mGrade[0] = atof(tempStr.c_str());
				}
				else if (count == 5)
				{
					listSV[cur].mGrade[1] = atof(tempStr.c_str());
				}
				else if (count == 6)
				{
					listSV[cur].mGrade[2] = atof(tempStr.c_str());
				}
				tempStr = "";

			}

			if (i + 1 == length)
			{
				if (count == 5)
				{
					listSV[cur].mGrade[2] = atof(tempStr.c_str());
				}
			}
			i++;
		}
		count = 0;
		cur++;
		delete[] temp;
	}
	fin.close();

	
}
