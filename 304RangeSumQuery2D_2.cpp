#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
	vector<vector<long long>> mvMatrix;
public:
	NumMatrix(vector<vector<int>>& matrix); // O(N*M) N=matrix.size() M=matrix[0].size()
	long long sumRegion(int row1, int col1, int row2, int col2); // O
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
//그냥 row==0, col==0인 경우에 전부 0값을 넣어 해결했다.
//0값을 넣고 새로 2차원 벡터를 만드니 코드를 조금 더 깔끔하게 작성할 수 있었지만(생성자 함수가 눈에 띄게 짧아졌다) 메모리낭비가 심할것으로 예상된다.
//지금 생성자 함수에서는 하나의 mvMatrix값을 할당하기 위해 4개의 값을 탐색하고 연산하는데 이 부분은 이전코드가 효율이 더 좋을 것 같다.
