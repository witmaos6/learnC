#include <iostream>
#include <vector>
#include "GraphVector.h"
#include "GraphNode.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Graph G;
	GraphN graph;

	G.Insert(graph, 5);
	G.Insert(graph, 10);
	G.Insert(graph, 3);
	G.Link(graph, 5, 3);
	G.DoubleLink(graph, 10, 3);
	G.Link(graph, 10, 5);
	G.GraphTraverse(graph);
	G.TraverseThisLinkedNode(graph, 10);
	G.TraverseThisLinkedNode(graph, 5);
	G.TraverseThisLinkedNode(graph, 3);
	G.TraverseThisPath(graph, 5);

	return 0;
}