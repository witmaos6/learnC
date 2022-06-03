#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
	vector<vector<long long>> mvMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix);
	long long sumRegion(int row1, int col1, int row2, int col2);
	void print2Dvector();
};


int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

    vector<vector<int>> matrix = { {3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5} };
    NumMatrix numMatrix(matrix);
	cout << numMatrix.sumRegion(2, 1, 4, 3) << '\n';
	cout << numMatrix.sumRegion(1, 1, 2, 2) << '\n';
	cout << numMatrix.sumRegion(1, 2, 2, 4) << '\n';
	numMatrix.print2Dvector();

	return 0;
}

NumMatrix::NumMatrix(vector<vector<int>>& matrix)
{
	mvMatrix.assign(matrix.size() + 1, vector<long long>(matrix[0].size() + 1));
	for (unsigned int row = 1; row < matrix.size() + 1; row++)
	{
		for (unsigned int column = 1; column < matrix[0].size() + 1; column++)
		{
			mvMatrix[row][column] = matrix[row - 1][column - 1] + mvMatrix[row - 1][column] + mvMatrix[row][column - 1] - mvMatrix[row - 1][column - 1];
		}
	}
}

long long NumMatrix::sumRegion(int row1, int col1, int row2, int col2)
{
	long long plus = mvMatrix[row2+1][col2+1] + mvMatrix[row1][col1];
	long long result = plus - mvMatrix[row1][col2+1] - mvMatrix[row2+1][col1];
	return  result;
}

void NumMatrix::print2Dvector()
{
	for (vector<long long> i : mvMatrix)
	{
		for (int e : i)
		{
			cout << e << ' ';
		}
		cout << '\n';
	}
}

