// 최소 두개 이상의 nums 값의 합이 k의 배수인 경우가 있다면 true를 반환하라. 0은 k의 배수에 포함된다.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	bool checkSubarraySum(vector<int>& nums, int k);
	bool CheckSubarraySumUsePrefixSum(vector<int>& nums, int k);
	bool bIsLeastTwoElement(int& FindIndex, int& CurrentIndex);
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

bool Solution::bIsLeastTwoElement(int& FindIndex, int& CurrentIndex)
{
	return(FindIndex - CurrentIndex > 1) ? true : false;
}

// 처음에는 우선 백트래킹으로 풀었다. 당연히 시간초과였기 때문에 다른방법을 생각했다.
// 연속하는 서브어레이기 때문에 누적합 알고리즘으로 접근했다. 탐색 횟수는 O(N^2)으로 같았기 때문에 다른 방법을 더 찾아야 했다.
// 누적합에 Mod k를 해서 키값으로 인덱스를 value값으로 저장한 후 탐색을 시도했다. 시간복잡도는 O(N)으로 축소된다.
