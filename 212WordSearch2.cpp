﻿#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Trie
{
	string S;
	vector<Trie*> Next;
	Trie() : S(), Next(26) {}
	Trie(string s) : S(s), Next(26) {}
};

class Solution
{
public:

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words);

	vector<string> findWordsUsingDFS(vector<vector<char>>& board, vector<string>& words);

private:
	vector<string> FoundWord;
	const char Visit = '.';
	int RowSize = 0;
	int ColSize = 0;

	Trie* BuildTrie(vector<string>& words);

	bool InBound(const int& row, const int& col);

	void DFSTrie(vector<vector<char>>& board, Trie* node, int row, int col);

	void DFS(vector<vector<char>>& board, string& word, int row, int col, int index);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution solution;
	vector<vector<char>> Board = { {'a','b','c'},{'a','e','d'},{'a','f','g'} };
	vector<string> Words = { "abcdefg","gfedcbaaa","eaabcdgfa","befa","dgc","ade" };

	vector<string> SearchWord = solution.findWords(Board, Words);

	for (string& word : SearchWord)
	{
		cout << word << ' ';
	}

	return 0;
}

vector<string> Solution::findWords(vector<vector<char>>& board, vector<string>& words)
{
	Trie* Root = BuildTrie(words);
	RowSize = static_cast<int>(board.size());
	ColSize = static_cast<int>(board[0].size());

	for (int row = 0; row < RowSize; row++)
	{
		for (int col = 0; col < ColSize; col++)
		{
			DFSTrie(board, Root, row, col);
		}
	}

	return FoundWord;
}

Trie* Solution::BuildTrie(vector<string>& words)
{
	Trie* Root = new Trie;

	for (string& word : words)
	{
		Trie* Node = Root;
		for (char& c : word)
		{
			if (!Node->Next[c - 'a'])
			{
				Node->Next[c - 'a'] = new Trie();
			}
			Node = Node->Next[c - 'a'];
		}
		Node->S = word;
	}
	return Root;
}

void Solution::DFSTrie(vector<vector<char>>& board, Trie* node, int row, int col)
{
	if (!InBound(row, col))
	{
		return;
	}
	char CurrentC = board[row][col];
	if (CurrentC == Visit || !node->Next[CurrentC - 'a'])
	{
		return;
	}

	node = node->Next[CurrentC - 'a'];
	if (!node->S.empty())
	{
		FoundWord.push_back(node->S);
		node->S.clear();
	}

	board[row][col] = Visit;
	DFSTrie(board, node, row + 1, col);
	DFSTrie(board, node, row - 1, col);
	DFSTrie(board, node, row, col + 1);
	DFSTrie(board, node, row, col - 1);

	board[row][col] = CurrentC;
}

bool Solution::InBound(const int& row, const int& col)
{
	return row >= 0 && row < RowSize&& col >= 0 && col < ColSize;
}

vector<string> Solution::findWordsUsingDFS(vector<vector<char>>& board, vector<string>& words)
{
	unordered_map<char, vector<string>> FirstChar;
	for (string& word : words)
	{
		FirstChar[word.front()].push_back(word);
	}
	RowSize = static_cast<int>(board.size());
	ColSize = static_cast<int>(board[0].size());

	for (int row = 0; row < RowSize; row++)
	{
		for (int col = 0; col < ColSize; col++)
		{
			char CurrentC = board[row][col];
			if (FirstChar.find(CurrentC) != FirstChar.end())
			{
				for (string& word : FirstChar[CurrentC])
				{
					int Index = 0;
					DFS(board, word, row, col, Index);
				}
				FoundWord.erase(unique(FoundWord.begin(), FoundWord.end()), FoundWord.end());
			}
		}
	}

	return FoundWord;
}

void Solution::DFS(vector<vector<char>>& board, string& word, int row, int col, int index)
{
	if (row >= RowSize || row < 0 || col >= ColSize || col < 0 || board[row][col] == Visit)
	{
		return;
	}
	if (word[index] == board[row][col])
	{
		char CurrentC = board[row][col];
		index++;
		board[row][col] = Visit;
		if (index == static_cast<int>(word.size()))
		{
			FoundWord.push_back(word);
			return;
		}
		DFS(board, word, row + 1, col, index);
		DFS(board, word, row - 1, col, index);
		DFS(board, word, row, col + 1, index);
		DFS(board, word, row, col - 1, index);
		board[row][col] = CurrentC;
	}
}
