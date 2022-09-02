// board에서 string을 찾아라 같은 셀의 문자는 중첩되지 않는다.
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
	bool exist(vector<vector<char>>& board, string word); // O(N*M)
	bool ExistChar(unsigned int row, unsigned int col, unsigned int i); // O(N*M)
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
// DFS로 문제를 풀었다. 지나간 문자에는 다시 접근할 수 없어 처음에는 2차원 배열을 생성하여 마킹하려고 했지만 메모리를 초과했다.
// discuss에서 마킹한 방식을 보고 배웠다.
