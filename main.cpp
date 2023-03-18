

#include "SinhVien.h"
int main()
{
	QLSinhVien qlsv;

	qlsv.inputListSV(3);
	//cout << endl << qlsv.mean();
	qlsv.classification();
	qlsv.printListSV();
	cout << endl;
	qlsv.lowerThanMean();
	cout << endl;
	qlsv.deleteSV(2);
	qlsv.printListSV();
	

	cout << endl << qlsv.mean();
}