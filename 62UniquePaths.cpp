// 0,0에서 m,n 까지 갈 수 있는 경우의 수를 구하라(중복은 안된다.)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int RowGoal;
	int ColGoal;
	vector<vector<int>> Paths;
	int uniquePaths(int m, int n);
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
	return Paths[m - 1][n - 1];
}
// DP를 이용하여 경우의 수를 구하는 문제다.
