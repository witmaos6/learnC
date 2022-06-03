// 2차원 벡터를 생성자를 이용하여 재구성하고 4개의 row, column값의 범위 안에 있는 값들의 합을 구하여라
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
	cout << numMatrix.sumRegion(2, 1, 4, 3);
	cout << numMatrix.sumRegion(1, 1, 2, 2);
	cout << numMatrix.sumRegion(1, 2, 2, 4);
	numMatrix.print2Dvector();

	return 0;
}

NumMatrix::NumMatrix(vector<vector<int>>& matrix)
{
	mvMatrix.assign(matrix.size() + 1, vector<long long>(matrix[0].size() + 1));
	int temp = 0;
	for (unsigned int row = 1; row < matrix.size() + 1; row++)
	{
		for (unsigned int column = 1; column < matrix[0].size() + 1; column++)
		{
			temp += matrix[row - 1][column - 1];
			mvMatrix[row][column] = temp + mvMatrix[row - 1][column];
		}
		temp = 0;
	}
}

long long NumMatrix::sumRegion(int row1, int col1, int row2, int col2)
{
	return  mvMatrix[row2 + 1][col2 + 1] + mvMatrix[row1][col1] - mvMatrix[row1][col2 + 1] - mvMatrix[row2 + 1][col1];
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
// DP를 이용하여 풀었으나 2차원 벡터의 크기가 작을 때 여러가지 문제 발생
// row==0인 경우와 column==0인 경우에 0값을 추가하여 코드 간소화
// 탐색은 줄였지만 연산이 늘어나서 인지 사이트에서는 시간차이가 별로 나지 않는다.
