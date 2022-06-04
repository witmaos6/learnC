#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& matrix); //O(N*M) N=matrix.size(), M=matrix[i].size()
	vector<vector<int>> squareTranspose(vector<vector<int>>& matrix); // O(sigmaN) N=matrix.size()-1, (N*N+1)/2
	void matrixSwap(vector<vector<int>>& matrix, int row, int column);
	void printVector(const vector<vector<int>>& matrix);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	vector<vector<int>>matrix = { {1,2,3} ,{4,5,6} };

	Solution solution;
	if(matrix.size()==matrix[0].size())
	{
		solution.squareTranspose(matrix);
	}
	else
	{
		matrix = solution.transpose(matrix);
	}
	solution.printVector(matrix);

	return 0;
}

vector<vector<int>> Solution::squareTranspose(vector<vector<int>>& matrix)
{
	for (unsigned int row = 0; row < matrix.size() - 1; row++)
	{
		for (unsigned int column = row + 1; column < matrix[row].size(); column++)
		{
			matrixSwap(matrix, row, column);
		}
	}
	return matrix;
}
void Solution::matrixSwap(vector<vector<int>>& matrix, int row, int column)
{
	int temp = matrix[row][column];
	matrix[row][column] = matrix[column][row];
	matrix[column][row] = temp;
}

vector<vector<int>> Solution::transpose(vector<vector<int>>& matrix)
{
	vector<vector<int>> rectangle(matrix[0].size(), vector<int>(matrix.size()));
	for (unsigned int column = 0; column < matrix[0].size(); column++)
	{
		for (unsigned int row = 0; row < matrix.size(); row++)
		{
			rectangle[column][row] = matrix[row][column];
		}
	}
	return rectangle;
}

void Solution::printVector(const vector<vector<int>>& matrix)
{
	for (vector<int> i : matrix)
	{
		for (auto j : i)
		{
			cout << j << ' ';
		}
		cout << '\n';
	}
}
//정사각형인 경우 더 빠르게 할 수 있을거라고 생각해서 알고리즘을 두개만들어 사용했다.
//이 방법이 더 효율적인지는 모르겠다.
