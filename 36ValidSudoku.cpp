// Sudoku board가 주어졌을 때 최초의 모습이 올바른지 검사하라(완전히 풀 수 있는 퍼즐인지는 검사하지 않는다.)
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool OptimizeIsValidSudoku(vector<vector<char>>& board);
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

bool Solution::OptimizeIsValidSudoku(vector<vector<char>>& board)
{
	vector<set<int>> Rows(9), Cols(9), Blocks(9);

	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (board[row][col] == '.')
			{
				continue;
			}
			int CurrentNumber = board[row][col]; // vector라면 -'0'를 해서 인덱스를 맞춰줘야 하지만 set는 그럴 필요가 없다. 원소들이 고유한지만 검사하면 된다.
			int BlockCheckOnly = (row / 3) * 3 + col / 3;
			if (Rows[row].count(CurrentNumber) ||
				Cols[col].count(CurrentNumber) ||
				Blocks[BlockCheckOnly].count(CurrentNumber))
			{
				return false;
			}

			Rows[row].insert(CurrentNumber);
			Cols[col].insert(CurrentNumber);
			Blocks[BlockCheckOnly].insert(CurrentNumber);
		}
	}
	return true;
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
// Row, Col, Block 3개 유형으로 탐색하는 함수를 만들어 실행했다. 시간내의 풀 수 있었지만 느린편에 속하는 알고리즘이었다.
// 최적화 함수는 dicuss에서 본건데 vector에 set<char>를 넣는 방식을 사용했다. 처음보는 방식이라 신기했다.
