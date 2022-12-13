// n * n matrix가 주어진다. 각 matrix[row][col] 은 matrix[row + 1][col - 1], matrix[row + 1][col], matrix[row + 1][col + 1]과 더한다.
// 이 떄 최소 값을 구하라.
class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        Length = static_cast<int>(matrix.size());
        DP(matrix, Length - 1);

        int MinSum = 10001;
        for(int col = 0; col < Length; col++)
        {
            MinSum = min(MinSum, matrix[0][col]);
        }

        return MinSum;
    }
private:
    array<int, 3> NextCol = {-1, 0, 1};
    int Length = 0;

    void DP(vector<vector<int>>& matrix, int row) // O(N^2) N == matrix.size()
    {
        if(row > 0)
        {
            for(int col = 0; col < Length; col++)
            {
                matrix[row - 1][col] += FindMinValue(matrix[row], col);
            }
            DP(matrix, row - 1);
        }
    }

    int FindMinValue(vector<int>& row, const int& col) // O(1)
    {
        int MinValue = 10001;
        for(int& next : NextCol)
        {
            if(col + next >= 0 && col + next < Length)
            {
                MinValue = min(MinValue, row[col + next]);
            }
        }
        return MinValue;
    }
};

// 처음에는 DFS로 접근했다. 당연히 시간초과가 났고 DP로 접근했는데 TopDown으로 풀 경우 그리디 알고리즘과 유사할 것이라 생각하여 Bottom Up으로 풀었다.
