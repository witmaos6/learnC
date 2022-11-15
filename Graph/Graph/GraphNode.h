#pragma once
using namespace std;

struct Node
{
	int Value;
	vector<Node*> LinkNode;
	Node(int value) : Value(value) {}
};

typedef vector<Node*> GraphN;

class Graph
{
public:
	void Insert(GraphN& graph, const int& value);

	void Link(GraphN& graph, const int& from, const int& to);

	void DoubleLink(GraphN& graph, const int& first, const int& second);

	void GraphTraverse(GraphN& graph);

	void TraverseThisLinkedNode(GraphN& graph, const int& value);

	void TraverseThisPath(GraphN& graph, const int& value);

private:
	Node* CreateNode(const int& value);

	Node* FindNode(GraphN& graph, const int& value);

	void PathHelper(Node* node, const int& currentValue, const int& value);

	bool bNotExist(Node* node);

	bool bIsExist(Node* node);

	const int NotExist = 404;
};

inline Node* Graph::CreateNode(const int& value)
{
	return new Node(value);
}

inline void Graph::Insert(GraphN& graph, const int& value)
{
	Node* NewNode = CreateNode(value);
	graph.push_back(NewNode);
}

inline void Graph::Link(GraphN& graph, const int& from, const int& to)
{
	Node* FromNode = FindNode(graph, from);
	Node* ToNode = FindNode(graph, to);

	if (!bNotExist(FromNode) && !bNotExist(ToNode))
	{
		FromNode->LinkNode.push_back(ToNode);
	}
	else
	{
		cout << "Failed Link\n";
	}
}

inline void Graph::DoubleLink(GraphN& graph, const int& first, const int& second)
{
	Node* FirstNode = FindNode(graph, first);
	Node* SecondNode = FindNode(graph, second);

	if (!bNotExist(FirstNode) && !bNotExist(SecondNode))
	{
		FirstNode->LinkNode.push_back(SecondNode);
		SecondNode->LinkNode.push_back(FirstNode);
	}
	else
	{
		cout << "Failed Link\n";
	}
}

inline void Graph::GraphTraverse(GraphN& graph)
{
	for (Node* node : graph)
	{
		cout << node->Value << ' ';
	}
	cout << '\n';
}

inline void Graph::TraverseThisLinkedNode(GraphN& graph, const int& value)
{
	Node* TraverseNode = FindNode(graph, value);

	if (bIsExist(TraverseNode))
	{
		cout << TraverseNode->Value << ": ";
		for (Node* node : TraverseNode->LinkNode)
		{
			cout << node->Value << ' ';
		}
		cout << '\n';
	}
	else
	{
		cout << "Failed Traverse\n";
	}
}

void Graph::TraverseThisPath(GraphN& graph, const int& value)
{
	Node* TraverseNode = FindNode(graph, value);

	if (bIsExist(TraverseNode))
	{
		cout << TraverseNode->Value << ": ";
		for (Node* node : TraverseNode->LinkNode)
		{
			cout << node->Value << ' ';
			PathHelper(node, value, value);
		}
		cout << '\n';
	}
	else
	{
		cout << "Failed Traverse\n";
	}
}

void Graph::PathHelper(Node* node, const int& currentValue, const int& value)
{
	for(Node* linkNode : node->LinkNode)
	{
		if (linkNode->Value != currentValue && linkNode->Value != value)
		{
			cout << linkNode->Value << ' ';
			PathHelper(linkNode, node->Value, value);
		}
	}
	cout << '\n';
}

inline Node* Graph::FindNode(GraphN& graph, const int& value)
{
	for (Node* node : graph)
	{
		if (node->Value == value)
		{
			return node;
		}
	}

	return new Node(NotExist);
}

inline bool Graph::bNotExist(Node* node)
{
	return node->Value == NotExist ? true : false;
}

inline bool Graph::bIsExist(Node* node)
{
	return node->Value != NotExist ? true : false;
}
