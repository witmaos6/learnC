#pragma once
using namespace std;

typedef vector<vector<bool>> GraphV;

class GraphVector
{
public:
	GraphV Initialize(const int& node);

	void Link(GraphV& graph, const int& from, const int& to);

	void DoubleLink(GraphV& graph, const int& first, const int& second);

	void PrintLinkedNode(GraphV& graph, const int& value);

	void Traverse(GraphV& graph);
private:
	int NumberOfNode = 0;

	bool bInBoundary(const int& value);
};

inline GraphV GraphVector::Initialize(const int& node)
{
	GraphV Graph(node, vector<bool>(node));

	NumberOfNode = node;

	return Graph;
}

inline void GraphVector::Link(GraphV& graph, const int& from, const int& to)
{
	if (!bInBoundary(from) || !bInBoundary(to))
	{
		cout << "입력할 수 없는 범위입니다.\n";
		return;
	}
	graph[from][to] = true;
}

inline void GraphVector::DoubleLink(GraphV& graph, const int& first, const int& second)
{
	if (!bInBoundary(first) || !bInBoundary(second))
	{
		cout << "입력할 수 없는 범위입니다.\n";
		return;
	}
	graph[first][second] = true;
	graph[second][first] = true;
}

inline void GraphVector::PrintLinkedNode(GraphV& graph, const int& value)
{
	if (!bInBoundary(value))
	{
		cout << "입력할 수 없는 범위입니다.\n";
		return;
	}
	for (int i = 0; i < NumberOfNode; i++)
	{
		if (graph[value][i])
		{
			cout << i << ' ';
		}
	}
	cout << '\n';
}

inline void GraphVector::Traverse(GraphV& graph)
{
	for (vector<bool>& row : graph)
	{
		for (bool col : row)
		{
			cout << col << ' ';
		}
		cout << '\n';
	}
}

inline bool GraphVector::bInBoundary(const int& value)
{
	return (value >= 0 && value < NumberOfNode) ? true : false;
}
