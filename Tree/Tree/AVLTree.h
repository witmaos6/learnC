#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int Value;
	Node* Left;
	Node* Right;
	int Height; // Height를 사용하지 않는 중, 지워도 상관없을 것 같다.
	Node(int value) : Value(value), Left(nullptr), Right(nullptr), Height(0) {}
};

class AVLTree
{
	Node* Root = nullptr;

public:
	void Insert(const int& value);

private:
	Node* CreateNode(const int& value);

	Node* InsertNode(Node* root, const int& value);

	int GetBalance(Node* node);

	int GetHeight(Node* node);

	Node* RightRotate(Node* node);

	Node* LeftRotate(Node* node);

public:
	void Delete(const int& value);

private:
	Node* DeleteNode(Node* root, const int& value);

	Node* MinValueNode(Node* node);

public:
	void BFS();

	void LevelOrder();

private:
	vector<queue<int>> LevelNode;

	void LevelPush(Node* node, int level);

	bool bIsLeafNode(Node* node);

	bool bHasLeftNode(Node* node);

	bool bHasRightNode(Node* node);
	
public:
	~AVLTree();
private:
	
	void MemoryClear(Node* node);
};

inline void AVLTree::Insert(const int& value)
{
	if (Root)
	{
		Root = InsertNode(Root, value);
	}
	else
	{
		Root = CreateNode(value);
	}
}

inline Node* AVLTree::InsertNode(Node* root, const int& value)
{
	if(root == nullptr)
	{
		return CreateNode(value);
	}
	if (root->Value > value)
	{
		root->Left = InsertNode(root->Left, value);
	}
	else if (root->Value < value)
	{
		root->Right = InsertNode(root->Right, value);
	}
	else if (root->Value == value)
	{
		cout << "중복된 값입니다.\n";
	}

	int CurrentBalance = GetBalance(root);

	if(CurrentBalance > 1)
	{
		if(GetBalance(root->Left) < 0)
		{
			root->Left = LeftRotate(root->Left);
		}
		return RightRotate(root);
	}
	if(CurrentBalance < -1)
	{
		if(GetBalance(root->Right) > 0)
		{
			root->Right = RightRotate(root->Right);
		}
		return LeftRotate(root);
	}

	return root;
}

inline Node* AVLTree::CreateNode(const int& value)
{
	return new Node(value);
}

inline int AVLTree::GetBalance(Node* node)
{
	return GetHeight(node->Left) - GetHeight(node->Right);
}

inline int AVLTree::GetHeight(Node* node)
{
	if (node)
	{
		return 1 + max(GetHeight(node->Left), GetHeight(node->Right));
	}
	return 0;
}

inline Node* AVLTree::RightRotate(Node* node)
{
	Node* NewRoot = node->Left;
	Node* MoveRight = NewRoot->Right;
	NewRoot->Right = node;
	node->Left = MoveRight;

	return NewRoot;
}

inline Node* AVLTree::LeftRotate(Node* node)
{
	Node* NewRoot = node->Right;
	Node* MoveLeft = NewRoot->Left;
	NewRoot->Left = node;
	node->Right = MoveLeft;

	return NewRoot;
}

inline void AVLTree::Delete(const int& value)
{
	Root = DeleteNode(Root, value);
}

inline Node* AVLTree::DeleteNode(Node* root, const int& value)
{
	if(root == nullptr)
	{
		return root;
	}
	if(root->Value > value)
	{
		root->Left = DeleteNode(root->Left, value);
	}
	else if(root->Value < value)
	{
		root->Right = DeleteNode(root->Right, value);
	}
	else if(root->Value == value)
	{
		if(!bHasRightNode(root))
		{
			Node* Temp = root->Left;
			delete root;
			root = nullptr;
			return Temp;
		}
		else if(!bHasLeftNode(root))
		{
			Node* Temp = root->Right;
			delete root;
			root = nullptr;
			return Temp;
		}
		Node* Temp = MinValueNode(root);
		root->Value = Temp->Value;
		root->Right = DeleteNode(root->Right, Temp->Value);
	}

	return root;
}

inline Node* AVLTree::MinValueNode(Node* node)
{
	if(bHasLeftNode(node))
	{
		return MinValueNode(node->Left);
	}
	return node;
}

inline void AVLTree::BFS()
{
	queue<Node*> BFSQ;
	BFSQ.push(Root);

	while(!BFSQ.empty())
	{
		Node* CurrentNode = BFSQ.front();
		BFSQ.pop();
		cout << CurrentNode->Value << ' ';

		if(bHasLeftNode(CurrentNode))
		{
			BFSQ.push(CurrentNode->Left);
		}
		if(bHasRightNode(CurrentNode))
		{
			BFSQ.push(CurrentNode->Right);
		}
	}
}

inline void AVLTree::LevelOrder()
{
	LevelNode.resize(10);

	LevelPush(Root, 0);

	for(queue<int>& level : LevelNode)
	{
		while (!level.empty())
		{
			cout << level.front() << ' ';
			level.pop();
		}
		cout << '\n';
	}
}

inline void AVLTree::LevelPush(Node* node, int level)
{
	if(node)
	{
		LevelNode[level].push(node->Value);
		level++;
		LevelPush(node->Left, level);
		LevelPush(node->Right, level);
	}
}

inline bool AVLTree::bIsLeafNode(Node* node)
{
	if (node->Left == nullptr && node->Right == nullptr)
	{
		return true;
	}
	return false;
}

bool AVLTree::bHasLeftNode(Node* node)
{
	return (node->Left != nullptr) ? true : false;
}

bool AVLTree::bHasRightNode(Node* node)
{
	return (node->Right != nullptr) ? true : false;
}

inline void AVLTree::MemoryClear(Node* node)
{
	if (bIsLeafNode(node))
	{
		delete node;
	}
	else
	{
		MemoryClear(node->Left);
		MemoryClear(node->Right);
		delete node;
	}
}

inline AVLTree::~AVLTree()
{
	MemoryClear(Root);
}
