#include "Stack.h"


Stack::Stack(int num)
{
	capacity = num;
	size = 0;
	ptr = new int[num];
}

void Stack::push(const int& Element)
{
	if (capacity == size)
	{
		cout << "STACK OVER";
	}


	else {
		ptr[size] = Element;
	}
	size++;
}

int Stack::pop()
{
	if (size == 0)
	{
		cout << "STACK EMPTY";
	}

	else {
		int last = ptr[size - 1];
		ptr[size - 1] = ptr[size];
		size--;
		return last;
	}

}
//
//void Stack::printStack()
//{
//	for (int i = 0; i < size ; i++)
//	{
//		cout << ptr[i] << " ";
//	}
//}

Stack::~Stack()
{

}