#pragma once
#include <vector>
using namespace std;

class Node
{
public:
	int Key = 0;
	int Value = 0;
	int HashValue = 0;
	int BucketNumber = 0;
	Node* Next = nullptr;

	Node(int key, int value, int hashValue, int bucketNumber) : Key(key), Value(value), HashValue(hashValue), BucketNumber(bucketNumber) {}
	Node(int key, int hashValue, int bucketNumber) : Key(key), HashValue(hashValue), BucketNumber(bucketNumber) {}
};

class UnorderedMap
{
public:
	vector<Node*> Umap{ 9 };

	void Insert(const int& key, const int& value);

	void Insert(const int& key);

	bool Find(const int& key);

	int GetValue(const int& key);

	void Delete(const int& key);

	void Traverse();

	void PrintNode(Node* node);

private:
	const int HashCoefficient = 13;

	const int NumberOfBucket = 9;

	const int NotFind = 404;

	void BucketTraverse(Node* node);

	Node Hashing(const int& key, const int& value);

	Node* CreateNode(const int& key, const int& value);

	Node* CreateFindNode(const int& key);

	void DeleteHeadNode(Node* head);
};

inline void UnorderedMap::Insert(const int& key, const int& value)
{
	Node* NewNode = CreateNode(key, value);
	int Bucket = NewNode->BucketNumber;

	if (Umap[Bucket] == nullptr)
	{
		Umap[Bucket] = NewNode;
	}
	else
	{
		Node* Head = Umap[Bucket];
		while (Head->Next != nullptr)
		{
			Head = Head->Next;
		}

		Head->Next = NewNode;
	}
}

inline void UnorderedMap::Insert(const int& key)
{
	Node* NewNode = CreateNode(key, 0);

	int Bucket = NewNode->BucketNumber;

	if (Umap[Bucket] == nullptr)
	{
		Umap[Bucket] = NewNode;
	}
	else
	{
		Node* Head = Umap[Bucket];
		while (Head->Next != nullptr)
		{
			Head = Head->Next;
		}

		Head->Next = NewNode;
	}
}

inline bool UnorderedMap::Find(const int& key)
{
	Node FindNode = Hashing(key, 0);

	if (Umap[FindNode.BucketNumber] != nullptr)
	{
		Node* TraverseNode = Umap[FindNode.BucketNumber];

		while (TraverseNode->Key != key && TraverseNode->Next != nullptr)
		{
			TraverseNode = TraverseNode->Next;
		}
		if (TraverseNode->Key == key)
		{
			return true;
		}
	}
	return false;
}

inline int UnorderedMap::GetValue(const int& key)
{
	Node FindNode = Hashing(key, 0);

	if (Umap[FindNode.BucketNumber] != nullptr)
	{
		Node* TraverseNode = Umap[FindNode.BucketNumber];

		while (TraverseNode->Key != key && TraverseNode->Next != nullptr)
		{
			TraverseNode = TraverseNode->Next;
		}
		if(TraverseNode->Key == key)
		{
			return TraverseNode->Value;
		}
	}

	cout << "존재하지 않는 key입니다.\n";
	return NotFind;
}

inline void UnorderedMap::Delete(const int& key)
{
	Node DeleteNode = Hashing(key, 0);

	if (Umap[DeleteNode.BucketNumber] != nullptr)
	{
		Node* Before = Umap[DeleteNode.BucketNumber];
		if (Before->Key == key)
		{
			DeleteHeadNode(Before);
			return;
		}
		Node* FindNode = Before->Next;

		while (FindNode->Key != key && FindNode != nullptr)
		{
			Before = Before->Next;
			FindNode = FindNode->Next;
		}

		if (FindNode == nullptr)
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

inline void UnorderedMap::DeleteHeadNode(Node* head)
{
	if(head->Next != nullptr)
	{
		*head = *head->Next;
	}
	else
	{
		Umap[head->BucketNumber] = nullptr;
		delete head;
	}
}

inline void UnorderedMap::Traverse()
{
	for (Node* node : Umap)
	{
		if (node)
		{
			BucketTraverse(node);
			cout << '\n';
		}
	}
}

inline void UnorderedMap::PrintNode(Node* node)
{
	cout << node->Key << ' ' << node->Value << ' ' << node->HashValue << ' ' << node->BucketNumber << '\n';
}

inline void UnorderedMap::BucketTraverse(Node* node)
{
	while (node != nullptr)
	{
		cout << node->Key << ' ' << node->Value << ' ';
		node = node->Next;
	}
}

inline Node* UnorderedMap::CreateNode(const int& key, const int& value)
{
	Node New = Hashing(key, value);
	return new Node(New.Key, New.Value, New.HashValue, New.BucketNumber);
}

inline Node* UnorderedMap::CreateFindNode(const int& key)
{
	Node Find = Hashing(key, 0);
	return new Node(Find.Key, Find.HashValue, Find.BucketNumber);
}

inline Node UnorderedMap::Hashing(const int& key, const int& value)
{
	int Hash = key;
	int HashValue = 0;
	int Exponent = 1;

	while (Hash > 0)
	{
		HashValue += (Hash % 10) * Exponent;
		Exponent *= HashCoefficient;
		Hash /= 10;
	}
	int BucketNumber = HashValue % NumberOfBucket;

	return Node(key, value, HashValue, BucketNumber);
}
