#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* Link;
};

class SingleList
{
public:
	Node* Head;

	SingleList(Node* create);

	void LinkedListHandler();

	Node* createHeadNode(int initialData);

	void addLastNode(Node* head, int data);

	void addThisNode(Node* head, int afterThisData, int addData);

	void deleteLastNode(Node* head);

	void deleteThisNode(Node* head, int deleteData);

	void deleteHeadNode(Node* head, int deleteData);

	void searchThisNode(Node* head, int thisData);

	void printList(Node* List);
};
