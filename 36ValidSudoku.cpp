#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board);
	bool bSearchSudokuRow(vector<vector<char>>& board, int Row);
	bool bSearchSudokuCol(vector<vector<char>>& board, int Col);
	bool bSearchSudokuSubbox(vector<vector<char>>& board, int TopLeft, int BottomRight);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<vector<char>> TrueCaseSudokuBoard = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};
	vector<vector<char>> FalseCaseSudokuBoard = {
		{'8','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	Solution solution;
	cout << solution.isValidSudoku(FalseCaseSudokuBoard);

	return 0;
}

bool Solution::isValidSudoku(vector<vector<char>>& board)
{
	for (int i = 0; i < 9; i++)
	{
		bool RowSearch = bSearchSudokuRow(board, i);
		bool ColSearch = bSearchSudokuCol(board, i);
		if (RowSearch && ColSearch)
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	for (int TopLeft = 0; TopLeft <= 6; TopLeft += 3)
	{
		for (int BottomRight = 0; BottomRight <= 6; BottomRight += 3)
		{
			if (!bSearchSudokuSubbox(board, TopLeft, BottomRight))
			{
				return false;
			}
		}

	}
	return true;
}

bool Solution::bSearchSudokuRow(vector<vector<char>>& board, int Row)
{
	set<char> DuplicateCheck;
	for (int i = 0; i < 9; i++)
	{
		if (board[Row][i] == '.')
		{
			continue;
		}
		if (DuplicateCheck.count(board[Row][i]) == 0)
		{
			DuplicateCheck.insert(board[Row][i]);
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool Solution::bSearchSudokuCol(vector<vector<char>>& board, int Col)
{
	set<char> DuplicateCheck;
	for (int i = 0; i < 9; i++)
	{
		if (board[i][Col] == '.')
		{
			continue;
		}
		if (DuplicateCheck.count(board[i][Col]) == 0)
		{
			DuplicateCheck.insert(board[i][Col]);
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool Solution::bSearchSudokuSubbox(vector<vector<char>>& board, int TopLeft, int BottomRight)
{
	set<char>DuplicateCheck;
	for (int row = TopLeft; row < TopLeft + 3; row++)
	{
		for (int col = BottomRight; col < BottomRight + 3; col++)
		{
			if (board[row][col] == '.')
			{
				continue;
			}
			if (DuplicateCheck.count(board[row][col]) == 0)
			{
				DuplicateCheck.insert(board[row][col]);
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}
