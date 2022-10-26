#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	bool checkSubarraySum(vector<int>& nums, int k);
	bool CheckSubarraySumUsePrefixSum(vector<int>& nums, int k);
	bool bIsLeastTwoElement(int Index, int Range);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution solution;
	vector<int> Nums = { 23,2,6,4,7 };
	int K = 6;

	cout << solution.CheckSubarraySumUsePrefixSum(Nums, K);

	return 0;
}

bool Solution::checkSubarraySum(vector<int>& nums, int k)
{
	vector<vector<int>> DP;
	int NumsSize = static_cast<int>(nums.size());
	if (NumsSize < 2)
	{
		return false;
	}
	DP.resize(NumsSize - 1);

	for (int Index = 0; Index < NumsSize - 1; Index++)
	{
		DP[Index].push_back(nums[Index] + nums[Index + 1]);
		if (DP[Index].back() % k == 0)
		{
			return true;
		}
		for (int i = Index + 2; i < NumsSize; i++)
		{
			DP[Index].push_back(DP[Index].back() + nums[i]);
			if (DP[Index].back() % k == 0)
			{
				return true;
			}
		}
	}

	return false;
}

bool Solution::CheckSubarraySumUsePrefixSum(vector<int>& nums, int k)
{
	int NumsSize = static_cast<int>(nums.size());
	if (NumsSize < 2)
	{
		return false;
	}
	unordered_map<int, int> PrefixMod = { {0, -1} };

	int PrefixSum = 0;

	for (int i = 0; i < NumsSize; i++)
	{
		PrefixSum += nums[i];
		PrefixSum %= k;

		if (PrefixMod.find(PrefixSum) != PrefixMod.end())
		{
			if (bIsLeastTwoElement(i, PrefixMod[PrefixSum]))
			{
				return true;
			}
		}
		else
		{
			PrefixMod[PrefixSum] = i;
		}
	}

	return false;
}

bool Solution::bIsLeastTwoElement(int Index, int Range)
{
	return(Index - Range > 1) ? true : false;
}
