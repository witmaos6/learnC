#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int HeadData;
	cout << "Head data를 입력하세요: ";
	cin >> HeadData;

	SingleList List(HeadData);
	cout << "리스트가 생성되었습니다. " << '\n';
	List.LinkedListHandler();

	return 0;
}

SingleList::SingleList(int headData)
{
	Head->Data = headData;
	Head->Link = nullptr;
}

void SingleList::LinkedListHandler()
{
	string Command;
	while (1)
	{
		cout << "명령을 입력하세요: " << '\n';
		cin >> Command;

		if (Command == "AddLastNode")
		{
			int TheNumberOfInputData;
			cout << "몇개의 data를 입력하시겠습니까: ";
			cin >> TheNumberOfInputData;
			int AddData;
			cout << "추가할 data를 입력하세요: ";
			for (int i = 0; i < TheNumberOfInputData; i++)
			{
				cin >> AddData;
				AddLastNode(AddData);
			}
		}
		else if (Command == "AddThisNode")
		{
			int AfterThisNode;
			int AddData;
			cout << "어떤 노드 뒤에 추가하실겁니까: ";
			cin >> AfterThisNode;
			cout << "추가할 data를 입력하세요: ";
			cin >> AddData;
			AddThisNode(AfterThisNode, AddData);
		}
		else if (Command == "SearchThisNode")
		{
			int SearchData;
			cout << "탐색할 노드의 data를 입력하세요: ";
			cin >> SearchData;
			SearchThisNode(SearchData);
		}
		else if (Command == "DeleteLastNode")
		{
			DeleteLastNode();
		}
		else if (Command == "DeleteThisNode")
		{
			int DeleteNode;
			cout << "삭제할 data를 입력하세요: ";
			cin >> DeleteNode;
			DeleteThisNode(DeleteNode);
		}
		else if (Command == "PrintList")
		{
			PrintList();
		}
		else if(Command == "Exit")
		{
			return;
		}
	}
}

void SingleList::AddLastNode(int data)
{
	Node* NewNode = new Node;
	Node* LastNode;
	NewNode->Data = data;
	NewNode->Link = nullptr;

	if (Head == nullptr)
	{
		Head = NewNode;
		return;
	}

	LastNode = Head;
	while (LastNode->Link != nullptr)
	{
		LastNode = LastNode->Link;
	}
	LastNode->Link = NewNode;
}

void SingleList::AddThisNode(int afterThisData, int addData)
{
	Node* PrevNodeOfToInsert;
	PrevNodeOfToInsert = Head;
	try
	{
		while (PrevNodeOfToInsert->Data != afterThisData)
		{
			if (PrevNodeOfToInsert->Link == nullptr)
			{
				throw PrevNodeOfToInsert;
			}
			PrevNodeOfToInsert = PrevNodeOfToInsert->Link;
		}
		Node* NewNode = new Node;
		NewNode->Data = addData;
		NewNode->Link = PrevNodeOfToInsert->Link;
		PrevNodeOfToInsert->Link = NewNode;
	}
	catch (Node* prevNodeOfToInsert)
	{
		cout << afterThisData << "를 가진 노드가 없습니다." << '\n';
		cout << prevNodeOfToInsert->Data << "가 마지막 데이터 입니다" << '\n';
	}
}

void SingleList::DeleteLastNode()
{
	Node* prevNodeOfToDelete;
	Node* deleteNode;

	if (Head == nullptr)
	{
		return;
	}
	if (Head->Link == nullptr)
	{
		delete Head;
		Head = nullptr;
	}
	else
	{
		prevNodeOfToDelete = Head;
		deleteNode = Head->Link;

		while (deleteNode->Link != nullptr)
		{
			prevNodeOfToDelete = deleteNode;
			deleteNode = prevNodeOfToDelete->Link;
		}
		free(deleteNode);
		prevNodeOfToDelete->Link = nullptr;
	}
}

void SingleList::DeleteThisNode(int deleteData)
{
	Node* prevNodeOfToDelete = Head->Link;
	Node* deleteNode;
	if (deleteData == Head->Data)
	{
		Head = prevNodeOfToDelete;
	}

	try
	{
		while (prevNodeOfToDelete->Link->Data != deleteData)
		{
			if (prevNodeOfToDelete->Link == nullptr)
			{
				throw prevNodeOfToDelete;
			}
			prevNodeOfToDelete = prevNodeOfToDelete->Link;
		}
		deleteNode = prevNodeOfToDelete->Link;
		prevNodeOfToDelete->Link = deleteNode->Link;
		free(deleteNode);
	}
	catch (Node* prevNodeOfToDelete)
	{
		cout << deleteData << "값을 가진 노드가 없습니다. " << '\n';
		cout << prevNodeOfToDelete->Data << "가 마지막 데이터 입니다." << '\n';
	}
}

void SingleList::DeleteHeadNode(int deleteData)
{
	//Head = Head->headNode->Link;
}

void SingleList::SearchThisNode(int thisData)
{
	Node* searchNode = Head;

	try
	{
		while (searchNode->Data != thisData)
		{
			if (searchNode->Link == nullptr)
			{
				throw searchNode;
			}
			searchNode = searchNode->Link;
		}
		cout << thisData << " Value를 찾았습니다. " << '\n';
	}
	catch (Node* searchNode)
	{
		cout << thisData << "값을 가진 노드가 없습니다. " << '\n';
		cout << searchNode->Data << "가 마지막 데이터 입니다. " << '\n';
	}
}

void SingleList::PrintList()
{
	Node* printNode = Head;
	cout << "리스트 출력 " << '\n';
	while (printNode != nullptr)
	{
		cout << printNode->Data;
		printNode = printNode->Link;
		if (printNode != nullptr)
		{
			cout << " -> ";
		}
	}
	cout << '\n';
}

SingleList::~SingleList()
{
	delete Head;
}
