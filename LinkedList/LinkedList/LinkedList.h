#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int Data;
	Node* Link;
};

class SingleList
{
public:
	Node* Head = new Node;

	SingleList(int headData);

	void LinkedListHandler();

	void AddLastNode(int data);

	void AddThisNode(int afterThisData, int addData);

	void DeleteLastNode();

	void DeleteThisNode(int deleteData);

	void DeleteHeadNode(int deleteData);

	void SearchThisNode(int thisData);

	void PrintList();

	~SingleList();
};
