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
	cout << "Head data�� �Է��ϼ���: ";
	cin >> initialData;
	ListNode = List.createHeadNode(initialData);

	cout << "���� ����Ʈ ���� �Ϸ�" << '\n';

	int AddData;
	cout << "���� ����Ʈ�� �߰��� Value�� �Է��ϼ���: ";
	for (int i = 0; i < 3; i++)
	{
		cin >> AddData;
		List.addLastNode(ListNode, AddData);
	}
	cout << '\n';
	List.printList(ListNode);
	cout << '\n';

	int SearchData;
	cout << "Ž���� ����� Value�� �Է��ϼ���: ";
	cin >> SearchData;
	List.searchThisNode(ListNode, SearchData);
	cout << '\n';

	int AfterThisData;
	cout << "� ��� �ڿ� �߰��Ͻ� �̴ϱ�?: ";
	cin >> AfterThisData;
	cout << "� Value�� ���� ��带 �߰��Ұǰ���?: ";
	cin >> AddData;
	List.addThisNode(ListNode, AfterThisData, AddData);
	List.printList(ListNode);
	cout << '\n';

	int DeleteNode;
	cout << "������ ��带 �Է����ּ���: ";
	cin >> DeleteNode;
	List.deleteThisNode(ListNode, DeleteNode);
	List.printList(ListNode);

	cout << "������ ��带 �����ϰڽ��ϴ�. " << '\n';
	List.deleteLastNode(ListNode);
	List.printList(ListNode);
	cout << '\n';

	cout << "���α׷��� �����մϴ�. bye bye";

	return 0;
}

SingleList::SingleList(Node* create)
{
	Head = create;
}

void SingleList::LinkedListHandler()
{
	string command;
	cout << "����� �Է��ϼ���. " << '\n';
	cin >> command;
	if(command == "create")
	{
		int initialData;
		cout << "Head data�� �Է��ϼ���: ";
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
		cout << afterThisData << " Value�� ���� ��尡 �����ϴ�." << '\n';
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
		cout << deleteData << "���� ���� ��尡 �����ϴ�. " << '\n';
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
		cout << thisData << " Value�� ã�ҽ��ϴ�. " << '\n';
	}
	catch (Node* searchNode)
	{
		cout << thisData << "���� ���� ��尡 �����ϴ�. " << '\n';
	}
}

void SingleList::printList(Node* List)
{
	Node* printNode = List;
	cout << " ����Ʈ ��� " << '\n';
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
