#pragma once
using namespace std;

struct Node
{
	string S; //  To do: for optimize
	vector<Node*> Next;
	Node() : S("."), Next(0) {}
};

class Trie
{
	const char StartPoint = '.';

	const int NotExist = -1;
public:
	Node* Create(const char& c);

	void Insert(Node* root, const string& s);

	bool Find(Node* root, const string& s);

	void Delete(Node* root, const string& s);

	void MemoryOptimize(Node* root, const string& first, const string& second);

	void Traverse(Node* root);

private:

	int FindCharLocation(vector<Node*> next, const char& c);

	bool bIsExist(const int& location);

	void MergeNode(Node* node, const string& second);
};

inline Node* Trie::Create(const char& c)
{
	Node* NewNode = new Node;
	NewNode->S = c;

	return NewNode;
}

inline void Trie::Insert(Node* root, const string& s)
{
	int Location = 0;
	for (const char& c : s)
	{
		Location = FindCharLocation(root->Next, c);
		if (bIsExist(Location))
		{
			root = root->Next[Location];
		}
		else
		{
			root->Next.push_back(Create(c));
			int NextLocation = static_cast<int>(root->Next.size()) - 1;
			root = root->Next[NextLocation];
		}
	}
}

inline bool Trie::Find(Node* root, const string& s)
{
	int Location = 0;
	for (const char& c : s)
	{
		Location = FindCharLocation(root->Next, c);
		if (bIsExist(Location))
		{
			root = root->Next[Location];
		}
		else
		{
			return false;
		}
	}
	return true;
}

inline void Trie::Delete(Node* root, const string& s)
{
	int Location = 0;
	for(Node* node : root->Next)
	{
		if(node->S == s)
		{
			for(Node* next : node->Next)
			{
				root->Next.push_back(next);
			}
			root->Next.erase(root->Next.begin() + Location);
			delete node;
			return;
		}
		Location++;
	}
	for(Node* node : root->Next)
	{
		Delete(node, s);
	}
}

inline void Trie::MemoryOptimize(Node* root, const string& first, const string& second)
{
	for(Node* node : root->Next)
	{
		if(node->S == first)
		{
			MergeNode(node, second);
			return;
		}
	}
	for(Node* node : root->Next)
	{
		MemoryOptimize(node, first, second);
	}
}

void Trie::MergeNode(Node* node, const string& second)
{
	if(node->Next.size() > 1)
	{
		cout << "최적화가 불가능합니다.\n";
		return;
	}

	Node* ToMergeNode = node->Next[0];

	if (ToMergeNode->S == second)
	{
		node->S += ToMergeNode->S;
		node->Next = ToMergeNode->Next;
		delete ToMergeNode;
	}
}

inline void Trie::Traverse(Node* root)
{
	for (Node* node : root->Next)
	{
		cout << node->S << ' ';
		Traverse(node);
	}
	cout << '\n';
}

inline int Trie::FindCharLocation(vector<Node*> next, const char& c)
{
	int Location = 0;
	for (Node* node : next)
	{
		if (c == node->S.front())
		{
			return Location;
		}
		Location++;
	}
	return NotExist;
}

inline bool Trie::bIsExist(const int& location)
{
	return location != NotExist ? true : false;
}
