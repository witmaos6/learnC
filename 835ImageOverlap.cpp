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

int Solution::largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2)
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

int Solution::CountNumberOfOverlap(vector<vector<int>>& image1, vector<vector<int>>& image2, int& ShiftRow, int& ShiftCol)
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

	for (int i = 0; i < SideLength; ++i) 
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

	for(unsigned int& bit : bits1)
	{
		cout << bit << ' ';
	}
	cout << '\n';
	for (unsigned int& bit : bits2)
	{
		cout << bit << ' ';
	}
	cout << '\n';

	int ans = 0;
	for (int i = -SideLength + 1; i < SideLength; ++i) 
	{
		for (int j = -SideLength + 1; j < SideLength; ++j) 
		{
			int overlap = 0;

			for (int k = 0; k < SideLength; ++k)
			{
				if (k + i >= 0 && k + i < SideLength) 
				{
					overlap += __popcnt(j < 0 ? bits1[k] & (bits2[k + i] << -j) : bits1[k] & (bits2[k + i] >> j));
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
