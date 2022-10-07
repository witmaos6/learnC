#pragma once

struct Node
{
	int value;
	Node* next;
};

struct List
{
	Node* Head;
	Node* Tail;
	List() : Head(nullptr), Tail(nullptr) {}
};

class LinkedList
{
public:
	Node* CreateNode(const int& val);

	bool bHaveNext(Node* node);

	void InsertTail(List& list, const int& val);

	void InsertThis(List& list , const int& val, const int& after);

	void DeleteThis(List& list, const int& val);

	void DeleteHead(List& list, Node* head);

	void Traverse(List list);
};

Node* LinkedList::CreateNode(const int& val)
{
	Node* NewNode = new Node;
	NewNode->value = val;
	NewNode->next = nullptr;
	return NewNode;
}

inline bool LinkedList::bHaveNext(Node* node)
{
	return node->next == nullptr ? false : true;
}

void LinkedList::InsertTail(List& list, const int& val)
{
	Node* InsertNode = CreateNode(val);
	if(list.Head == nullptr)
	{
		list.Head = InsertNode;
		list.Tail = InsertNode;
		return;
	}
	list.Tail->next = InsertNode;
	list.Tail = InsertNode;
}
void LinkedList::InsertThis(List& list, const int& val, const int& after)
{
	Node* head = list.Head;
	while(bHaveNext(head) && head->value != after)
	{
		head = head->next;
	}
	if (head->value == after)
	{
		Node* InsertNode = CreateNode(val);
		if (head->next != nullptr)
		{
			Node* After = head->next;
			head->next = InsertNode;
			InsertNode->next = After;
		}
		else
		{
			head->next = InsertNode;
			list.Tail = InsertNode;
		}
	}
	else // "Tail에 Insert 하시겠습니까?" 를 물어보는게 좋을까?
	{
		std::cout << "해당값은 존재하지 않습니다. " << '\n';
	}
}

inline void LinkedList::DeleteThis(List& list, const int& val)
{
	Node* head = list.Head;
	if(list.Head->value == val)
	{
		DeleteHead(list, head);
		return;
	}		
	Node* DeleteNode = head->next;

	while(bHaveNext(DeleteNode) && DeleteNode->value != val)
	{
		head = head->next;
		DeleteNode = DeleteNode->next;
	}
	if(DeleteNode->value == val)
	{
		if(bHaveNext(DeleteNode))
		{
			Node* NextNode = DeleteNode->next;
			head->next = NextNode;
		}
		else
		{
			head->next = nullptr;
			list.Tail = head;
		}
		delete DeleteNode;
	}
	else
	{
		std::cout << "해당값은 존재하지 않습니다. " << '\n';
	}
}

inline void LinkedList::DeleteHead(List& list, Node* head)
{
	if(head->next == nullptr)
	{
		list.Head = nullptr;
	}
	else
	{
		list.Head = head->next;	
	}
	delete head;
}

inline void LinkedList::Traverse(List list)
{
	Node* head = list.Head;
	while(head != nullptr)
	{
		std::cout << head->value << ' ';
		head = head->next;
	}
	std::cout << '\n';
}
