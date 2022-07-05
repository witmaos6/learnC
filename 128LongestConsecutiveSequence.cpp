#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	vector<int> Nums = { 100,4,200,1,3,2 };
	Solution solution;
	cout << solution.longestConsecutive(Nums);

	return 0;
}

int Solution::longestConsecutive(vector<int>& nums)
{
	unordered_set<int> ToSearchSet(nums.begin(), nums.end());
	int LengthTheLongest = 0;
	for (const int& num : ToSearchSet)
	{
		if (ToSearchSet.count(num - 1))
		{
			continue;
		}
		int ConsecutiveElements = 1;
		while (ToSearchSet.count(num + ConsecutiveElements))
		{
			ConsecutiveElements++;
		}
		if (LengthTheLongest < ConsecutiveElements)
		{
			LengthTheLongest = ConsecutiveElements;
		}
	}
	return LengthTheLongest;
}
