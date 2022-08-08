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

int Solution::lengthOfLIS(vector<int>& nums)
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
	for (int& current : nums)
	{
		if (LIS == 0 || nums[LIS - 1] < current)
		{
			nums[LIS++] = current;
		}
		else
		{
			*lower_bound(begin(nums), begin(nums) + LIS, current) = current;
		}
	}
	return LIS;
}
