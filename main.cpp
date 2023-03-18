#include "Stack.h"
#include "List.h"
int main()
{
	List myList;
	myList.insert(0, "hihi");

	myList.insert(0, "haha");
	myList.erase(1);			
	cout << myList.size();
	myList.print();

}