#include "SinhVien.h"

int main() {

	QLSinhVien qlsv;
	/*
	qlsv.inputListSV(3);
	//cout << endl << qlsv.mean();
	qlsv.classification();
	qlsv.printListSV();
	cout << endl;
	qlsv.lowerThanMean();
	cout << endl;
	qlsv.deleteSV(2);
	qlsv.printListSV();
	*/

	// Xuat ra file CSV
	// qlsv.writeToFile("reportcard.csv");

	// Doc tu file CSV
	qlsv.readFromFile("reportcard.csv");

	// Xuat ra console
	qlsv.printListSV();

	// listOfSV.lowerThanMean();

	cout << "\n";

	cout << "Happi Byrthday\n";
	qlsv.printListBirthday();

	return 0;
}