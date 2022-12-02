#pragma once
#include <array>
#include <iostream>
using namespace std;

class Node
{
public:
	int Key = 0;
	int HashValue = 0;
	int BucketNumber = 0;
	Node* Next = nullptr;

	Node(int key, int hashValue, int bucketNumber) : Key(key), HashValue(hashValue), BucketNumber(bucketNumber) {}
};

class UnorderedSet
{
public:
	array<Node*, 9> Uset{ nullptr };

	void Insert(const int& value);

	bool Find(const int& value);

	void Delete(const int& value);

	void Traverse();

	void PrintNode(Node* node);
private:
	const int HashCoefficient = 13;

	const int NumberOfBucket = 9;

	void BucketTraverse(Node* node);

	Node Hashing(const int& value);

	Node* CreateNode(const int& value);

	void DeleteHeadNode(Node* head);
};

inline void UnorderedSet::Insert(const int& value)
{
	Node* NewNode = CreateNode(value);
	int Bucket = NewNode->BucketNumber;

	if (Uset[Bucket] == nullptr)
	{
		Uset[Bucket] = NewNode;
	}
	else
	{
		Node* Head = Uset[Bucket];
		while (Head->Next != nullptr)
		{
			Head = Head->Next;
		}

		Head->Next = NewNode;
	}
}

inline bool UnorderedSet::Find(const int& value)
{
	Node FindNode = Hashing(value);

	if (Uset[FindNode.BucketNumber] != nullptr)
	{
		Node* TraverseNode = Uset[FindNode.BucketNumber];

		while (TraverseNode->Key != value && TraverseNode->Next != nullptr)
		{
			TraverseNode = TraverseNode->Next;
		}
		if (TraverseNode->Key == value)
		{
			return true;
		}
	}
	return false;
}

inline void UnorderedSet::Delete(const int& value)
{
	Node DeleteNode = Hashing(value);

	if(Uset[DeleteNode.BucketNumber] != nullptr)
	{
		Node* Before = Uset[DeleteNode.BucketNumber];
		if(Before->Key == value)
		{
			DeleteHeadNode(Before);
			return;
		}
		Node* FindNode = Before->Next;

		while(FindNode->Key != value && FindNode != nullptr)
		{
			Before = Before->Next;
			FindNode = FindNode->Next;
		}

		if(FindNode == nullptr)
		{
			Before->Next = nullptr;
		}
		else
		{
			Before->Next = FindNode->Next;
		}
		delete FindNode;
	}
}

inline void UnorderedSet::DeleteHeadNode(Node* head)
{
	if(head->Next != nullptr)
	{
		*head = *head->Next;
	}
	else
	{
		Uset[head->BucketNumber] = nullptr;
		delete head;
	}
}

inline void UnorderedSet::Traverse()
{
	for(Node* node : Uset)
	{
		if(node)
		{
			BucketTraverse(node);
			cout << '\n';
		}
	}
}

inline void UnorderedSet::PrintNode(Node* node)
{
	cout << node->Key << ' ' << node->HashValue << ' ' << node->BucketNumber << '\n';
}

inline void UnorderedSet::BucketTraverse(Node* node)
{
	while(node != nullptr)
	{
		cout << node->Key << ' ';
		node = node->Next;
	}
}

inline Node UnorderedSet::Hashing(const int& value)
{
	int Hash = value;
	int HashValue = 0;
	int Exponent = 1;

	while (Hash > 0)
	{
		HashValue += (Hash % 10) * Exponent;
		Exponent *= HashCoefficient;
		Hash /= 10;
	}
	int BucketNumber = HashValue % NumberOfBucket;

	return Node(value, HashValue, BucketNumber);
}

inline Node* UnorderedSet::CreateNode(const int& value)
{
	Node New = Hashing(value);
	return new Node(New.Key, New.HashValue, New.BucketNumber);
}
