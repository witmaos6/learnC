#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<char>> Board;
	string Word;
	size_t WordLength = 0;
	size_t RowSize = 0;
	size_t ColSize = 0;
	bool exist(vector<vector<char>>& board, string word);
	bool ExistChar(unsigned int row, unsigned int col, unsigned int i);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution solution;
	vector<vector<char>> Board = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};
	string Word = "ABCB";
	cout << solution.exist(Board, Word);

	return 0;
}

bool Solution::exist(vector<vector<char>>& board, string word)
{
	Board = board;
	Word = word;
	WordLength = size(word);
	RowSize = size(board);
	ColSize = size(board[0]);

	for (unsigned int row = 0; row < RowSize; row++)
	{
		for (unsigned int col = 0; col < ColSize; col++)
		{
			if (board[row][col] == word[0] && ExistChar(row, col, 0))
			{
				return true;
			}
		}
	}
	return false;
}

bool Solution::ExistChar(unsigned int row, unsigned int col, unsigned int i)
{
	if (i == WordLength)
	{
		return true;
	}
	if (row >= RowSize || col >= ColSize || Board[row][col] != Word[i])
	{
		return false;
	}
	Board[row][col] = '0';

	bool Status = ExistChar(row + 1, col, i + 1) ||
		ExistChar(row, col + 1, i + 1) ||
		ExistChar(row - 1, col, i + 1) ||
		ExistChar(row, col - 1, i + 1);

	Board[row][col] = Word[i];
	return Status;
}
