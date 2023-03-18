#include "List.h"

List::List()
{
	head = new Node;
	head->data = "";
	head->next = NULL;
	count = 0;
}

Node* List::makeNode(const string& val)
{
	Node* newNode = new Node;

	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

List::~List()
{

}

void List::insert(int pos, const string& val) {
	if (count == 0)
	{
		head = makeNode(val);
		count++;
		return;
	}

	Node* curNode = head;
	for (int i = 0; i < pos - 1; i++)
	{
		curNode = curNode->next;
	}

	Node* tempNode = curNode->next;
	Node* insertedNode = makeNode(val);
	
	curNode->next = insertedNode;
	insertedNode->next = tempNode;
	count++;
}

void List::erase(int pos)
{
	if (head == NULL)
	{
		return;
	}

	Node* curNode = head;
	for (int i = 0; i < pos - 1; i++)
	{
		curNode = curNode->next;
	}

	Node* delNode = curNode->next;
	curNode->next = delNode->next;

	free(delNode);
	count--;

}

string List::get(int pos) 
{
	if (pos >= count)
	{
		cout << "OUT OF RANGE!";
		return "";
	}
	Node* curNode = head;
	for (int i = 1; i < pos; i++)
	{
		curNode = curNode->next;
	}
	return curNode->data;
}

void List::print()
{
	Node* curNode = head;
	for (int i = 0; i < count; i++)
	{
		cout << "[" << i << "]: " << curNode->data << "  /  ";
		curNode = curNode->next;
	}
}

int List::size()
{
	return count;
}