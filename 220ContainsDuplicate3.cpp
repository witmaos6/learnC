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

bool Solution::containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff)
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
