#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Node
{
	string data;
	Node* next;
};


class List
{
private: 
	Node* head;
	int count;
	Node* makeNode(const string& val);
public:
	List();
	~List();
	void insert(int pos, const string& val);
	void erase(int pos);
	string get(int pos);
	void print() ;
	int size() ;

	friend class Stack;
};

class Stack
{
private:
	List stack;

public:
	Stack(string val);
	Stack();
	~Stack();
	void push(const string& Element);
	string pop();
	void printStack();

};