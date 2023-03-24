#include "QLSinhVien.h";

QLSinhVien::QLSinhVien()
{
	listSV = new SinhVien[101];
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
	char* fileName = new char[20];
	strcpy(fileName, "LowerThanMean.csv");
	for (int i = 0; i < mSize; i++)
	{
		if (listSV[i].stdAvg() < this->mean()) {
			listSV[i].printSV();
			listSV[i].writeToFile(listSV[i], fileName);
		}
	}
	delete[] fileName;
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
	++mSize;
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

}// add list birthday

void QLSinhVien::writeToFile(string file)
{
	char* fileNameChar = new char[20];
	strcpy(fileNameChar, file.c_str());
	for (int i = 0; i < mSize; i++)
		listSV[i].writeToFile(listSV[i], fileNameChar);

	delete[] fileNameChar;
	return;
}// add 
void QLSinhVien::readFromFile(string file)
{

}
