// 하나의 이미지를 상하좌우로 움직여서 다른 이미지와 비교할 수 있다. 이미지를 움직였을 때 이미지 크기의 범위를 벗어나는 것은 전부 없앤다.
// 이미지를 움직여서 다른 이미지와 비교하고 오버랩되는 1의 최대 개수를 구하여라 ,이미지는 정방행렬이며 두개의 이미의 크기는 같다.
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int SideLength = 0;

	int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2);
	int CountNumberOfOverlap(vector<vector<int>>& image1, vector<vector<int>>& image2, int& ShiftRow, int& ShiftCol);

	int largestOverlapUsingBits(vector<vector<int>>& img1, vector<vector<int>>& img2);

	void PrintMaxrix(vector<vector<int>>& matrix);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution solution;

	vector<vector<int>> Image1 = { {1,1,0},{0,1,0},{0,1,0} }, Image2 = { {0,0,0},{0,1,1},{0,0,1} };

	cout << solution.largestOverlapUsingBits(Image1, Image2);

	return 0;
}

int Solution::largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) //O(N^2) N == img1.size(); (N*2-1)^2 만큼의 연산이 필요하다.
{
	SideLength = static_cast<int>(img1.size());
	int MaxNumberOfOverlap = INT_MIN;

	for (int row = -SideLength + 1; row < SideLength; row++)
	{
		for (int col = -SideLength + 1; col < SideLength; col++)
		{
			MaxNumberOfOverlap = max(MaxNumberOfOverlap, CountNumberOfOverlap(img1, img2, row, col));
		}
	}

	return MaxNumberOfOverlap;
}

int Solution::CountNumberOfOverlap(vector<vector<int>>& image1, vector<vector<int>>& image2, int& ShiftRow, int& ShiftCol) // O(N^2)
{
	int NumberOfOverlap = 0;

	for (int row = 0; row < SideLength; row++)
	{
		for (int col = 0; col < SideLength; col++)
		{
			if ((SideLength > row + ShiftRow && row + ShiftRow >= 0) && (SideLength > col + ShiftCol && col + ShiftCol >= 0))
			{
				if(image1[row+ShiftRow][col+ShiftCol] & image2[row][col])
				{
					NumberOfOverlap++;
				}
			}
		}
	}
	return NumberOfOverlap;
}

int Solution::largestOverlapUsingBits(vector<vector<int>>& img1, vector<vector<int>>& img2)
{
	SideLength = static_cast<int>(img1.size());
	vector<unsigned int> bits1, bits2;

	for (int i = 0; i < SideLength; ++i) // O(N^2) N == img1.size();
	{
		int b1 = 0, b2 = 0;

		for (int j = 0; j < SideLength; ++j) 
		{
			b1 = (b1 << 1) | img1[i][j];
			b2 = (b2 << 1) | img2[i][j];
		}
		bits1.push_back(b1);
		bits2.push_back(b2);
	}

	int ans = 0;
	for (int i = -SideLength + 1; i < SideLength; ++i) // O(N^3)
	{
		for (int j = -SideLength + 1; j < SideLength; ++j) 
		{
			int overlap = 0;

			for (int k = 0; k < SideLength; ++k)
			{
				if (k + i >= 0 && k + i < SideLength) 
				{
					overlap += __popcnt(j < 0 ? bits1[k] & (bits2[k + i] << -j) : bits1[k] & (bits2[k + i] >> j));
					//gcc 환경에서는 __builtin_popcount 함수를 쓰면 된다.
					//visual studio는 MSVC기 때문에 __popcnt를 사용했다.
				}
			}
			ans = max(ans, overlap);
		}
	}

	return ans;
}

void Solution::PrintMaxrix(vector<vector<int>>& matrix)
{
	for (vector<int>& row : matrix)
	{
		for (int& col : row)
		{
			cout << col << ' ';
		}
		cout << '\n';
	}
}
// 처음에는 DFS로 접근하려 했으나 탐색해야 하는 범위가 일정하다는 것을 파악하고 백트래킹으로 풀었다.
// Overlap 계산은 O(N^2) 이동은 O(N^2) 이동할 때마다 Overlap계산을 하기 때문에 최종 시간복잡도는 O(N^4)이다.
// UsingBits는 시간복잡도가 O(N^3)인데 어떤식으로 동작하는지 이해가 좀 필요하다.
