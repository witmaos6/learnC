#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Node* ListNode;
	SingleList List(ListNode);
	int initialData;
	cout << "Head data를 입력하세요: ";
	cin >> initialData;
	ListNode = List.createHeadNode(initialData);

	cout << "연결 리스트 생성 완료" << '\n';

	int AddData;
	cout << "연결 리스트에 추가할 Value를 입력하세요: ";
	for (int i = 0; i < 3; i++)
	{
		cin >> AddData;
		List.addLastNode(ListNode, AddData);
	}
	cout << '\n';
	List.printList(ListNode);
	cout << '\n';

	int SearchData;
	cout << "탐색할 노드의 Value를 입력하세요: ";
	cin >> SearchData;
	List.searchThisNode(ListNode, SearchData);
	cout << '\n';

	int AfterThisData;
	cout << "어떤 노드 뒤에 추가하실 겁니까?: ";
	cin >> AfterThisData;
	cout << "어떤 Value를 가진 노드를 추가할건가요?: ";
	cin >> AddData;
	List.addThisNode(ListNode, AfterThisData, AddData);
	List.printList(ListNode);
	cout << '\n';

	int DeleteNode;
	cout << "삭제할 노드를 입력해주세요: ";
	cin >> DeleteNode;
	List.deleteThisNode(ListNode, DeleteNode);
	List.printList(ListNode);

	cout << "마지막 노드를 삭제하겠습니다. " << '\n';
	List.deleteLastNode(ListNode);
	List.printList(ListNode);
	cout << '\n';

	cout << "프로그램을 종료합니다. bye bye";

	return 0;
}

SingleList::SingleList(Node* create)
{
	Head = create;
}

void SingleList::LinkedListHandler()
{
	string command;
	cout << "명령을 입력하세요. " << '\n';
	cin >> command;
	if(command == "create")
	{
		int initialData;
		cout << "Head data를 입력하세요: ";
		cin >> initialData;
		
	}
}

Node* SingleList::createHeadNode(int initialData)
{
	Node* Head = new Node;
	Head->data = initialData;
	Head->Link = nullptr;
	return Head;
}

void SingleList::addLastNode(Node* head, int data)
{
	Node* NewNode = new Node;
	Node* LastNode;
	NewNode->data = data;
	NewNode->Link = nullptr;

	if (head == nullptr)
	{
		head = NewNode;
		return;
	}

	LastNode = head;
	while (LastNode->Link != nullptr)
	{
		LastNode = LastNode->Link;
	}
	LastNode->Link = NewNode;
}

void SingleList::addThisNode(Node* head, int afterThisData, int addData)
{
	Node* prevNodeOfToInsert;
	prevNodeOfToInsert = head;
	try
	{
		while (prevNodeOfToInsert->data != afterThisData)
		{
			prevNodeOfToInsert = prevNodeOfToInsert->Link;
			if (prevNodeOfToInsert == nullptr)
			{
				throw prevNodeOfToInsert;
			}
		}
		Node* NewNode = new Node;
		NewNode->data = addData;
		NewNode->Link = prevNodeOfToInsert->Link;
		prevNodeOfToInsert->Link = NewNode;
	}
	catch (Node* prevNodeOfToInsert)
	{
		cout << afterThisData << " Value를 가진 노드가 없습니다." << '\n';
	}
}

void SingleList::deleteLastNode(Node* head)
{
	Node* prevNodeOfToDelete;
	Node* deleteNode;

	if (head == nullptr)
	{
		return;
	}
	if (head->Link == nullptr)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		prevNodeOfToDelete = head;
		deleteNode = head->Link;

		while (deleteNode->Link != nullptr)
		{
			prevNodeOfToDelete = deleteNode;
			deleteNode = prevNodeOfToDelete->Link;
		}
		free(deleteNode);
		prevNodeOfToDelete->Link = nullptr;
	}
}

void SingleList::deleteThisNode(Node* head, int deleteData)
{
	Node* prevNodeOfToDelete = head->Link;
	Node* deleteNode;
	if (deleteData == head->data)
	{
		head = prevNodeOfToDelete;
	}

	try
	{
		while (prevNodeOfToDelete->Link->data != deleteData)
		{
			prevNodeOfToDelete = prevNodeOfToDelete->Link;
			if (prevNodeOfToDelete == nullptr)
			{
				throw prevNodeOfToDelete;
			}
		}
		deleteNode = prevNodeOfToDelete->Link;
		prevNodeOfToDelete->Link = deleteNode->Link;
		free(deleteNode);
	}
	catch (Node* prevNodeOfToDelete)
	{
		cout << deleteData << "값을 가진 노드가 없습니다. " << '\n';
	}
}

void SingleList::deleteHeadNode(Node* head, int deleteData)
{
	//head = head->headNode->Link;
}

void SingleList::searchThisNode(Node* head, int thisData)
{
	Node* searchNode = head;

	try
	{
		while (searchNode->data != thisData)
		{
			searchNode = searchNode->Link;
			if (searchNode == nullptr)
			{
				throw searchNode;
			}
		}
		cout << thisData << " Value를 찾았습니다. " << '\n';
	}
	catch (Node* searchNode)
	{
		cout << thisData << "값을 가진 노드가 없습니다. " << '\n';
	}
}

void SingleList::printList(Node* List)
{
	Node* printNode = List;
	cout << " 리스트 출력 " << '\n';
	while (printNode != nullptr)
	{
		cout << printNode->data;
		printNode = printNode->Link;
		if (printNode != nullptr)
		{
			cout << " -> ";
		}
	}
	cout << '\n';
}
