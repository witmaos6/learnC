#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int RowGoal;
	int ColGoal;
	vector<vector<int>> Paths;
	int uniquePaths(int m, int n);
	void searchPath(int row, int col);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int GridRow = 3;
	int GridCol = 7;
	Solution solution;

	cout << solution.uniquePaths(GridRow, GridCol);

	return 0;
}

int Solution::uniquePaths(int m, int n)
{
	RowGoal = m;
	ColGoal = n;
	Paths.resize(m, vector<int>(n));
	for(int i=0;i<m;i++)
	{
		Paths[i][0] = 1;
	}
	for(int i=0;i<n;i++)
	{
		Paths[0][i] = 1;
	}
	for(int row=1;row<m;row++)
	{
		for(int col=1;col<n;col++)
		{
			Paths[row][col] = Paths[row - 1][col] + Paths[row][col - 1];
		}
	}
	int xStart = 0;
	int yStart = 0;
	return Paths[m - 1][n - 1];
}

void Solution::searchPath(int row, int col)
{
	if (row >= RowGoal - 1 || col >= ColGoal - 1)
	{
		return;
	}
	
}
