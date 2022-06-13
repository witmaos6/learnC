// 2차원 벡터가 주어졌을 때 가장 작은 값의 pathsum을 구하여라
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle);
    // O(N+M) N==triangle.size()+triangle[row++].size(), M==triangle[triangle.size()-1].size()
    int minimumTotalBottomUp(vector<vector<int>>& triangle);
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<vector<int>> Triangle = { {2},{3,4},{6,5,7},{4,1,8,3} };
    Solution solution;
	cout << solution.minimumTotalBottomUp(Triangle);

    return 0;
}

int Solution::minimumTotal(vector<vector<int>>& triangle)
{
    int MinimumPathSum = triangle[0][0];
    const int TriangleRowSize = (int)triangle.size();
	if (TriangleRowSize == 1)
    {
        return MinimumPathSum;
    }
    else if(TriangleRowSize == 2)
    {
        MinimumPathSum += min(triangle[1][0], triangle[1][1]);
        return MinimumPathSum;
    }

    triangle[1][0] += triangle[0][0];
    triangle[1][1] += triangle[0][0];
	for (int row = 2; row < TriangleRowSize; row++)
    {
		for (int col = 0; col < (int)triangle[row].size(); col++)
	    {
			if (col == 0)
            {
                triangle[row][col] += triangle[row - 1][col];
            }
			else if (col == (int)triangle[row].size() - 1)
            {
                triangle[row][col] += triangle[row - 1][col - 1];
            }
            else
            {
                triangle[row][col] += min(triangle[row - 1][col - 1], triangle[row - 1][col]);
            }
	    }
    }
    MinimumPathSum = *min_element(triangle[TriangleRowSize - 1].begin(), triangle[TriangleRowSize - 1].end());

    return MinimumPathSum;
}

int Solution::minimumTotalBottomUp(vector<vector<int>>& triangle)
{
	for (int row = (int)triangle.size() - 2; row >= 0; row--)
	{
		for (int col = 0; col < (int)triangle[row].size(); col++)
		{
            triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1]);
		}
	}
    return triangle[0][0];
}
// TopDown과 BottomUp 두개의 풀이를 사용해본 결과 사이트 기준으로 TopDown이 메모리는 더 사용하지만 속도는 더 빨랐다.
