#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill);
void Memoization(const vector<int>& Record, vector<vector<int>>& TotalRecord);
void PrefixSum(vector<vector<int>>& TotalRecord, const size_t& RowSize, const size_t& ColSize);
void PrintMatrix(vector<vector<int>>& Matrix);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<vector<int>> Board = {
		{5,5,5,5,5},
		{5,5,5,5,5},
		{5,5,5,5,5},
		{5,5,5,5,5}
	};
	vector<vector<int>> Skill = {
		{1,0,0,3,4,4},
		{1,2,0,2,3,2},
		{2,1,0,3,1,2},
		{1,0,1,3,3,1}
	};

	cout << solution(Board, Skill) << '\n';

	return 0;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
	int answer = 0;
	size_t RowSize = board.size();
	size_t ColSize = board[0].size();
	vector<vector<int>> TotalRecord(RowSize + 1, vector<int>(ColSize + 1));

	for (vector<int>& Record : skill) // O(S) S == skill.size();
	{
		Memoization(Record, TotalRecord);
	}

	PrefixSum(TotalRecord, RowSize, ColSize);
	
	for (size_t row = 0; row < RowSize; row++) // O(R*C) R==RowSize, C == ColSize
	{
		for (size_t col = 0; col < ColSize; col++)
		{
			if (board[row][col] + TotalRecord[row][col] > 0)
			{
				answer++;
			}
		}
	}

	return answer;
}

void Memoization(const vector<int>& Record, vector<vector<int>>& TotalRecord) //O(1)
{
	int Degree = Record[5];
	if (Record[0] == 1)
	{
		Degree *= -1;
	}

	TotalRecord[Record[1]][Record[2]] += Degree;
	TotalRecord[Record[3] + 1][Record[4] + 1] += Degree;

	TotalRecord[Record[1]][Record[4] + 1] -= Degree;
	TotalRecord[Record[3] + 1][Record[2]] -= Degree;
}

void PrefixSum(vector<vector<int>>& TotalRecord, const size_t& RowSize, const size_t& ColSize) // O(R*C) R==RowSize, C == ColSize
{
	for (size_t row = 0; row <= RowSize; row++)
	{
		for (size_t col = 0; col < ColSize; col++)
		{
			TotalRecord[row][col + 1] += TotalRecord[row][col];
		}
	}
	for (size_t col = 0; col <= ColSize; col++)
	{
		for (size_t row = 0; row < RowSize; row++)
		{
			TotalRecord[row + 1][col] += TotalRecord[row][col];
		}
	}
}

void PrintMatrix(vector<vector<int>>& Matrix)
{
	for(vector<int>& row : Matrix)
	{
		for(int& col : row)
		{
			cout << col << ' ';
		}
		cout << '\n';
	}
}
// PrefixSum 은 누적합을 계산하는 방법 중 하나다. Record를 읽을 때마다 TotalRecord에 영향이 가는 모든 셀을 바꿔주는 것이 아닌 4개의 지점에다가 표시만 해놓는다.
// 표시된 부분을 읽어서 부분합을 계산하는 방식이다. 
