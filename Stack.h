#pragma once
#include <iostream>
#include <string>

using namespace std;

class Stack
{
public:
	Stack(int);
	~Stack();
	void push(const int& Element);
	int pop();
	void printStack();

private:
	int* ptr;
	int capacity;
	int size;
};
