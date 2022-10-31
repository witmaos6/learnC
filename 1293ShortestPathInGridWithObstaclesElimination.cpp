#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	int Visit = 2;
	int ArrivalRow = 0;
	int ArrivalCol = 0;

	int ShortestPath = INT_MAX;
	int shortestPath(vector<vector<int>>& grid, int k);
	void DFS(vector<vector<int>> grid, int k, int Row, int Col, int CountMove);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution solution;
	vector<vector<int>> Grid = { {0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0 } };
	int K = 1;
	cout << solution.shortestPath(Grid, K) << '\n';

	return 0;
}

int Solution::shortestPath(vector<vector<int>>& grid, int k)
{
	ArrivalRow = static_cast<int>(grid.size());
	ArrivalCol = static_cast<int>(grid[0].size());
	vector<vector<int>> Visited(ArrivalRow, vector<int>(ArrivalCol, -1));
	queue<vector<int>> BFS;
	BFS.push({ 0,0,0,k });

	while (!BFS.empty())
	{
		vector<int> Current = BFS.front();
		BFS.pop();

		int Row = Current[0], Col = Current[1],CountMove = Current[2], CurrentK = Current[3];
		if (Row < 0 || Row >= ArrivalRow || Col < 0 || Col >= ArrivalCol)
		{
			continue;
		}

		if (Row == ArrivalRow - 1 && Col == ArrivalCol - 1)
		{
			return CountMove;
		}

		if (grid[Row][Col] == 1)
		{
			if (CurrentK > 0)
			{
				CurrentK--;
			}
			else
			{
				continue;
			}
		}

		if (Visited[Row][Col] != -1 && Visited[Row][Col] >= CurrentK)
		{
			continue;
		}

		Visited[Row][Col] = CurrentK;
		CountMove++;

		BFS.push({ Row + 1, Col, CountMove, CurrentK });
		BFS.push({ Row - 1, Col, CountMove, CurrentK });
		BFS.push({ Row, Col + 1, CountMove, CurrentK });
		BFS.push({ Row, Col - 1, CountMove, CurrentK });
	}

	return -1;
}

void Solution::DFS(vector<vector<int>> grid, int k, int Row, int Col, int CountMove)
{
	if (Row > ArrivalRow || Row < 0 || Col > ArrivalCol || Col < 0 || grid[Row][Col] == Visit)
	{
		return;
	}
	if (Row == ArrivalRow && Col == ArrivalCol)
	{
		ShortestPath = min(ShortestPath, CountMove);
		return;
	}
	if (grid[Row][Col] == 1)
	{
		if (k > 0)
		{
			k--;
		}
		else if (k == 0)
		{
			return;
		}
	}

	grid[Row][Col] = Visit;
	CountMove++;

	DFS(grid, k, Row + 1, Col, CountMove);
	DFS(grid, k, Row - 1, Col, CountMove);
	DFS(grid, k, Row, Col + 1, CountMove);
	DFS(grid, k, Row, Col - 1, CountMove);
}
