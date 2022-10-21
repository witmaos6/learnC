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

		if (nums[i] < 0)
		{
			--Bucket;
		}
		if (Buckets.find(Bucket) != Buckets.end())
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
		if (Buckets.size() > indexDiff)
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
// 
