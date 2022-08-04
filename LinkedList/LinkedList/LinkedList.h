#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int Data;
	Node* Link;
};

class SingleList
{
public:
	vector<string> CommandList = {"AddLastNode","AddThisNode","DeleteLastNode","DeleteThisNode",
		"SearchThisNode", "PrintList"
	};

	Node* Head = new Node;

	SingleList(int headData);

	void LinkedListHandler();

	void AddLastNode(int data);

	void AddThisNode(int afterThisData, int addData);

	void DeleteLastNode();

	void DeleteThisNode(int deleteData);

	void DeleteHeadNode();

	void SearchThisNode(int thisData);

	void PrintList();

	~SingleList();
};
