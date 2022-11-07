#include <iostream>
#include <string>
#include <vector>
#include "Trie.h"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Trie trie;
	Node* Root = new Node();

	trie.Insert(Root, "abc");
	trie.Insert(Root, "abcd");
	trie.Insert(Root, "def");
	trie.Insert(Root, "deh");
	trie.Traverse(Root);
	trie.MemoryOptimize(Root, "c", "d");
	trie.Traverse(Root);

	return 0;
}