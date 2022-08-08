// 가장 긴 오름차순 Subsequence를 구하라, Subsequence는 element를 삭제한 경우는 포함되나 변경은 포함하지 않는다.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums);
	int LengthOfLISBinarySearch(vector<int>& nums);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> Nums = { 10,9,2,5,3,7,101,18 };
	Solution solution;
	cout << solution.LengthOfLISBinarySearch(Nums);

	return 0;
}

int Solution::lengthOfLIS(vector<int>& nums) //O(N^2)
{
	int NumsSize = static_cast<int>(size(nums));
	vector<int> dp(NumsSize, 1);
	int LIS = 1;
	for (int i = 0; i < NumsSize; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				LIS = max(LIS, dp[i]);
			}
		}
	}
	return LIS;
}

int Solution::LengthOfLISBinarySearch(vector<int>& nums)
{
	int LIS = 0;
	for (int& current : nums) // O(N)
	{
		if (LIS == 0 || nums[LIS - 1] < current)
		{
			nums[LIS++] = current;
		}
		else
		{
			*lower_bound(begin(nums), begin(nums) + LIS, current) = current; // O(logN)
		}
	}
	return LIS;
}
//처음에는 재귀함수로 시도했는데 오차가 발생했다. discuss를 참고하여 return 값인 LIS를 따로 저장하는 방식을 알아내서 풀었다.
// BinarySearch로 푸는 방식은 잘 이해가 안되었지만 NlogN의 시간복잡도를 보장하는 함수라서 가져와봤다.
