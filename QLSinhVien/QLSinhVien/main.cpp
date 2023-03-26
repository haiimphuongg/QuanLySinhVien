#define _CRT_SECURE_NO_DEPRECATE

#include "SinhVien.h";
#include "QLSinhVien.h";

void Menu()
{
	int n;
	QLSinhVien myList;
	int size;
	cout << "Chuong trinh bat dau.\n";
	cout << "Ban muon tu nhap du lieu hay lay du lieu tu file DanhSachSV.csv?\n";
	cout << "Nhan 1 de nhap du lieu, 2 de lay du lieu tu file.\n";
	
	while (true)
	{
		cin >> n;
		if (n == 1)
		{
			cout << "Nhap so luong sinh vien ban muon nhap: ";
			cin >> size;
			cin.ignore();
			cout << "Bat dau nhap: \n";
			myList.inputListSV(size);
			break;
		}
		else if (n == 2)
		{
			myList.readFromFile("DanhSachSV.csv");
			cout << "Du lieu da duoc doc!\n";
			myList.printListSV();
			break;
		}
	}
	

	while (true)
	{
		cout << "\nChon lenh ban muon thuc hien voi du lieu: \n";
		cout << "1. Xuat ra tap tin LowerThanMean.csv nhung sinh vien co diem trung binh thap hon diem trung binh cua lop.\n";
		cout << "2. Them sinh vien vao danh sach.\n";
		cout << "3. Xep loai sinh vien, in ket qua ra man hinh.\n";
		cout << "4. Tim cac sinh vien co ngay sinh nhat vao hom nay.\n";
		cout << "5. Xuat danh sach tu file DanhSachSV.csv\n";
		cout << "6. Ghi danh sach vao file.\n";

		cin >> n;
		cin.ignore();

		if (n == 1)
		{
			myList.lowerThanMean();
			cout << "\nDiem trung binh la :" << myList.mean() << endl;
			cout << "\nDa cap nhat danh sach cac sinh vien co diem duoi trung binh vao file LowerThanMean.csv.\n";
		}
		else if (n == 2)
		{
			cout << "\nNhap thong tin sinh vien duoc them vao!\n";
			SinhVien newSV;
			newSV.inputSV();
			myList.insertSV(newSV);
			myList.writeToFile("DanhSachSV.csv");
			cout << "\nDa cap nhat vao tap tin DanhSachSV.csv";
			cout << "\nDanh sach da duoc cap nhat: \n";
			myList.printListSV();
		}
		else if (n == 3)
		{
			cout << "\nDanh sach sinh vien sau khi duoc xep loai:\n";
			myList.classification();
			myList.printListSV();

		}
		else if (n == 4)
		{
			cout << "\nDanh sach sinh vien co ngay sinh vao hom nay: \n";
			myList.printListBirthday();
		}
		else if (n == 5)
		{
			myList.readFromFile("DanhSachSV.csv");
			cout << "\nDanh sach doc tu file: \n";
			myList.printListSV();
		}
		else if (n == 6)
		{
			char* fileName = new char[100];
			cout << "\nNhap ten file ban muon luu du lieu: \n";
			cin.getline(fileName, 100);
			myList.printListSV();
			myList.writeToFile(fileName);
		}
		else
		{
			cout << "\nLenh nhap khong hop le!";
		}


		cout << "\nDa hoan thanh yeu cau! Nhap 0 de ket thuc chuong trinh, 1 de tiep tuc chuong trinh.\n";
		cin >> n;
		if (n == 0)
		{
			break;
		}
		else if ( n != 1) {
			cout << "Lenh khong hop le! Ket thuc chuong trinh!";
			break;
		}

	}
}
int main()
{
	Menu();
}