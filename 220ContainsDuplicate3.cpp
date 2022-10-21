// nums와 indexDiff, valueDiff가 주어진다. i!=j 일 때 nums[i] == nums[j], abs(i-j) <= indexDiff, abs(nums[i]-nums[j]) <= valueDiff 조건이 성립하는 쌍이 있다면 true반환
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution solution;

	vector<int> Nums = { 1,5,9,1,5,9 };
	int IndexDiff = 2;
	int ValueDiff = 3;

	cout << solution.containsNearbyAlmostDuplicate(Nums, IndexDiff, ValueDiff);

	return 0;
}

bool Solution::containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) // O(N) N==nums.size();
{
	int NumsSize = static_cast<int>(nums.size());
	unordered_map<int, int> Buckets;

	for (int i = 0; i < NumsSize; i++)
	{
		int Bucket = nums[i] / (valueDiff + 1);

		if (nums[i] < 0) // 음수일 경우에는 감소연산자를 써줘야 한다. -1/2는 0이 되기 때문이다.
		{
			--Bucket;
		}
		if (Buckets.find(Bucket) != Buckets.end()) // 같은 Bucket안에 있다는 것은 abs(nums[i]-nums[j]) 가 성립한다는 것이다.
		{
			return true;
		}
		Buckets[Bucket] = nums[i];
		if (Buckets.find(Bucket - 1) != Buckets.end() && nums[i] - Buckets[Bucket - 1] <= valueDiff)
		{
			return true;
		}
		if (Buckets.find(Bucket + 1) != Buckets.end() && Buckets[Bucket + 1] - nums[i] <= valueDiff)
		{
			return true;
		}
		if (Buckets.size() > indexDiff) // unordered_map의 크리를 indexDiff로 유지하면 abs(i-j) <= indexDiff 조건을 유지시킬 수 있다.
		{
			int Key = nums[i - indexDiff] / (valueDiff + 1);

			if (nums[i - indexDiff] < 0)
			{
				--Key;
			}
			Buckets.erase(Key);
		}
	}

	return false;
}
// 처음에는 abs(i-j) <= indexDiff가 성립하는 경우들을 탐색하며 abs(nums[i]-nums[j]) <= valueDiff인 경우를 탐색했는데 시간초과가 떴다.
// Unordered_map으로 SubSet을 만들어 시도를 했다가 음수 파트에서 막혀 Discuss를 확인하여 그 문제를 알아내고 풀었다.
