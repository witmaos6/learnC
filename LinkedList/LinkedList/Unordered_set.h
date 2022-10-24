#pragma once
#include <vector>

#include "LinkedList.h"
using namespace std;

struct Hash
{
	int Key;
	int HashValue;
	int BucketNumber;
	Hash(int key, int hashValue, int bucketNumber) : Key(key), HashValue(hashValue), BucketNumber(bucketNumber) {}
};

class Unordered_set : public LinkedList
{
private:
	const int HashingCoefficient = 13;
	int NumberOfBucket = 9;

	bool Find(Hash& Find);
public:
	vector<List> Uset{9};

	Hash Hashing(int Key);

	void Insert(const int& Key);

	bool Find(const int& Key);

	void Delete(const int& Key);

	void UsetTraverse();
};

inline Hash Unordered_set::Hashing(int Key)
{
	int OriginalKey = Key;
	int HashValue = 0;
	int Exponent = 1;

	while (Key > 0)
	{
		HashValue += (Key % 10) * Exponent;
		Key /= 10;
		Exponent *= HashingCoefficient;
	}
	int BucketNumber = HashValue % NumberOfBucket;

	return Hash(OriginalKey, HashValue, BucketNumber);
}

inline void Unordered_set::Insert(const int& Key)
{
	Hash NewHash = Hashing(Key);
	if (Find(NewHash))
	{
		cout << "�����ϴ� Key�� �Դϴ�.\n";
	}
	else
	{
		InsertTail(Uset[NewHash.BucketNumber], Key);
	}
}

bool Unordered_set::Find(Hash& Find)
{
	List FindList = Uset[Find.BucketNumber];
	Node* head = FindList.Head;

	if (head == nullptr)
	{
		return false;
	}
	while (head->next != nullptr && head->value != Find.Key)
	{
		head = head->next;
	}

	return (head->value == Find.Key) ? true : false;
}

inline bool Unordered_set::Find(const int& Key)
{
	Hash FindHash = Hashing(Key);
	List FindList = Uset[FindHash.BucketNumber];
	Node* head = FindList.Head;

	while (head->next != nullptr && head->value != Key)
	{
		head = head->next;
	}

	return (head->value == Key) ? true : false;
}

inline void Unordered_set::Delete(const int& Key)
{
	Hash DeleteHash = Hashing(Key);
	List DeleteList = Uset[DeleteHash.BucketNumber];

	if(DeleteList.Head == nullptr)
	{
		std::cout << "�ش簪�� �������� �ʽ��ϴ�. " << '\n';
	}
	else
	{
		DeleteThis(DeleteList, Key);
	}
}

inline void Unordered_set::UsetTraverse()
{
	for (List& list : Uset)
	{
		if(list.Head != nullptr)
		{
			Traverse(list);
		}
	}
}
