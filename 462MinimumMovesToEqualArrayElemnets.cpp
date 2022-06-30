#include <iostream>
#include <vector>
#include <algorithm>
#include "462MinimumMovesToEqualArrayElemnets.h"
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	vector<int> nums = { 1,2,3 };
	Solution solution;
	cout << solution.minMoves2(nums);

	return 0;
}

int Solution::MinMovesBruteForce(vector<int>& nums)
{
	int N = (int)nums.size();
	int Sum = 0;
	sort(nums.begin(), nums.end());
	int median = nums[N / 2];

	cout << median << '\n';
	for (int num : nums)
	{
		Sum += abs(num - median);
	}
	return Sum;
}

int Solution::minMoves2(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int median = nums.size() / 2;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += abs(nums[median] - nums[i]);
	}
	return sum;
}
