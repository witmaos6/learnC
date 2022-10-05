// 0은 바다 1은 육지라고 했을 때 동서남북이 바다로 둘러싸인 경우 하나의 섬이다. 섬의 개수를 구하라
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
		Point(unsigned int row, unsigned int col) : Row(row), Col(col) {}
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

int Solution::numIslands(vector<vector<char>>& grid) // O(N^2)
{
	int NumberOfiSland = 0;
	RowSize = static_cast<unsigned int>(size(grid));
	ColSize = static_cast<unsigned int>(size(grid[0]));

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

void Solution::DFS(vector<vector<char>>& grid, Point p) // 
{
	if (p.Row >= RowSize || p.Col >= ColSize || grid[p.Row][p.Col] == Invitation || grid[p.Row][p.Col] == '0')
	{
		return;
	}

	grid[p.Row][p.Col] = Invitation;
	DFS(grid, Point(p.Row + 1, p.Col));
	if (p.Col != 0)
	{
		DFS(grid, Point(p.Row, p.Col - 1));
	}
	if (p.Row != 0)
	{
		DFS(grid, Point(p.Row - 1, p.Col));
	}
	DFS(grid, Point(p.Row, p.Col + 1));
}
// Grid의 row와 col 값을 int i, int j 에서 구조체를 이용해 Point p로 바꿔봤다.
// 파라미터는 간소화 되긴 했지만 그렇다고 읽기 더 쉬운 코드가 된 것 같지는 않다.
// 특히 DFS안에서 DFS함수를 호출 할 때는 원본의 변경 없이 Row의 값만 바꿔야 되는데 그래서 더 복잡해졌다.
