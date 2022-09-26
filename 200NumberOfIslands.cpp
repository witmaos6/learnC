#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	struct Point
	{
		unsigned int Row = 0;
		unsigned int Col = 0;
	};
	unsigned int RowSize = 0;
	unsigned int ColSize = 0;
	char Invitation = '2';
	int numIslands(vector<vector<char>>& grid);
	void DFS(vector<vector<char>>& grid, Point p);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution solution;
	vector<vector<char>> Grid = {
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'}
	};
	cout << solution.numIslands(Grid);

	return 0;
}

int Solution::numIslands(vector<vector<char>>& grid)
{
	int NumberOfiSland = 0;
	RowSize = size(grid);
	ColSize = size(grid[0]);

	for (unsigned int i = 0; i < RowSize; i++)
	{
		for (unsigned int j = 0; j < ColSize; j++)
		{
			if (grid[i][j] == '1')
			{
				Point p;
				p.Row = i;
				p.Col = j;
				DFS(grid, p);
				NumberOfiSland++;
			}
		}
	}
	return NumberOfiSland;
}

void Solution::DFS(vector<vector<char>>& grid, Point p)
{
	if (p.Row >= RowSize || p.Col >= ColSize || grid[p.Row][p.Col] == Invitation || grid[p.Row][p.Col] == '0')
	{
		return;
	}

	grid[p.Row][p.Col] = Invitation;
	DFS(grid, Point{ p.Row + 1, p.Col });
	if (p.Col != 0)
	{
		DFS(grid, Point{ p.Row, p.Col - 1 });
	}
	if (p.Row != 0)
	{
		DFS(grid, Point{ p.Row - 1, p.Col });
	}
	DFS(grid, Point{ p.Row, p.Col + 1 });
}
