#pragma once
#include <queue>
#include <stack>
using namespace std;

struct Node
{
	int Value;
	Node* Left;
	Node* Right;
	Node(int value) : Value(value), Left(nullptr), Right(nullptr) {}
};

class Tree
{
public:
	Node* CreateNode(const int& value);

	void Insert(Node* root, const int& value);

	void Delete(Node* root, const int& value);

	bool Find(Node* root, const int& value);

	void BFS(Node* root);

	void DFS(Node* root);

	void PreOrder(Node* root);

	void InOrder(Node* root);

	void PostOrder(Node* root);

private:
	Node* FindParentOfDeleteNode(Node* parent, Node* node, const int& target);

	Node* FindDeleteTarget(Node* parent, const int& target);

	vector<queue<int>> BFSQueue{ 5 };

	void LevelOrder(Node* node, int Index);

	stack<int> DFSStack;

	bool bHaveLeft(Node* node);

	bool bHaveRight(Node* node);

	bool bIsLeafNode(Node* node);
};

inline Node* Tree::CreateNode(const int& value)
{
	Node* NewNode = new Node(value);

	return NewNode;
}

inline void Tree::Insert(Node* root, const int& value)
{
	if (root->Value < value)
	{
		if (!bHaveRight(root))
		{
			Node* InsertNode = CreateNode(value);
			root->Right = InsertNode;
		}
		else
		{
			Insert(root->Right, value);
		}
	}
	else if (root->Value > value)
	{
		if (!bHaveLeft(root))
		{
			Node* InsertNode = CreateNode(value);
			root->Left = InsertNode;
		}
		else
		{
			Insert(root->Left, value);
		}
	}
	else if (root->Value == value)
	{
		cout << "중복된 값입니다.\n";
	}
}

inline void Tree::Delete(Node* root, const int& value)
{
	Node* ParentOfDeleteNode = FindParentOfDeleteNode(root, root, value);

	if (ParentOfDeleteNode)
	{
		Node* DeleteNode = FindDeleteTarget(ParentOfDeleteNode, value);
		if (bIsLeafNode(DeleteNode))
		{
			if (value > ParentOfDeleteNode->Value)
			{
				ParentOfDeleteNode->Right = nullptr;
			}
			else
			{
				ParentOfDeleteNode->Left = nullptr;
			}
		}
		else if (!bHaveRight(DeleteNode))
		{
			if (value > ParentOfDeleteNode->Value)
			{
				ParentOfDeleteNode->Right = DeleteNode->Left;
			}
			else
			{
				ParentOfDeleteNode->Left = DeleteNode->Left;
			}
		}
		else if (!bHaveLeft(DeleteNode))
		{
			if (value > ParentOfDeleteNode->Value)
			{
				ParentOfDeleteNode->Right = DeleteNode->Right;
			}
			else
			{
				ParentOfDeleteNode->Left = DeleteNode->Right;
			}
		}
		else
		{
			if(value < ParentOfDeleteNode->Value)
			{
				ParentOfDeleteNode->Left = DeleteNode->Right;
				DeleteNode->Right->Left = DeleteNode->Left;
			}
			else
			{
				ParentOfDeleteNode->Right = DeleteNode->Left;
				DeleteNode->Left->Right = DeleteNode->Right;
			}
		}
		delete DeleteNode;
	}
	else
	{
		cout << "존재하지 않는 값입니다.\n";
	}
}

Node* Tree::FindParentOfDeleteNode(Node* parent, Node* node, const int& target)
{
	if (node->Value == target)
	{
		return parent;
	}
	if (node->Value < target)
	{
		return FindParentOfDeleteNode(node, node->Right, target);
	}
	if (node->Value > target)
	{
		return FindParentOfDeleteNode(node, node->Left, target);
	}
	return nullptr;
}

Node* Tree::FindDeleteTarget(Node* parent, const int& target)
{
	if (bHaveLeft(parent) && parent->Left->Value == target)
	{
		return parent->Left;
	}
	return parent->Right;
}

inline bool Tree::Find(Node* root, const int& value)
{
	while (root->Value != value)
	{
		if (root->Value < value)
		{
			if (bHaveRight(root))
			{
				root = root->Right;
			}
			else
			{
				return false;
			}
		}
		else if (root->Value > value)
		{
			if (bHaveLeft(root))
			{
				root = root->Left;
			}
			else
			{
				return false;
			}
		}
	}

	return root->Value == value ? true : false;
}

inline void Tree::BFS(Node* root)
{
	if (root == nullptr)
	{
		cout << "트리가 비어있습니다.\n";
		return;
	}
	LevelOrder(root, 0);

	for (queue<int>& q : BFSQueue)
	{
		while (!q.empty())
		{
			cout << q.front() << ' ';
			q.pop();
		}
		cout << '\n';
	}
}

inline void Tree::LevelOrder(Node* node, int Index)
{
	if (node == nullptr)
	{
		return;
	}
	BFSQueue[Index].push(node->Value);
	LevelOrder(node->Left, Index + 1);
	LevelOrder(node->Right, Index + 1);
}

inline void Tree::DFS(Node* root)
{
	if (root)
	{
		DFSStack.push(root->Value);
	}
	if (bHaveLeft(root))
	{
		DFS(root->Left);
	}
	if (bHaveRight(root))
	{
		DFS(root->Right);
	}
	cout << DFSStack.top() << ' ';
	DFSStack.pop();
}

inline void Tree::PreOrder(Node* root)
{
	if (root)
	{
		cout << root->Value << ' ';
		PreOrder(root->Left);
		PreOrder(root->Right);
	}
}

inline void Tree::InOrder(Node* root)
{
	if (root)
	{
		InOrder(root->Left);
		cout << root->Value << ' ';
		InOrder(root->Right);
	}
}

inline void Tree::PostOrder(Node* root)
{
	if (root)
	{
		PostOrder(root->Left);
		PostOrder(root->Right);
		cout << root->Value << ' ';
	}
}

inline bool Tree::bHaveLeft(Node* node)
{
	return node->Left != nullptr ? true : false;
}

inline bool Tree::bHaveRight(Node* node)
{
	return node->Right != nullptr ? true : false;
}

inline bool Tree::bIsLeafNode(Node* node)
{
	return (node->Left == nullptr && node->Right == nullptr) ? true : false;
}
