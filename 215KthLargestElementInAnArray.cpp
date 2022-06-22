#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int SortSolution(vector<int>& nums, int k); // O(NlogN) N==nums.size()
	int PQSolution(vector<int>& nums, int k); //O(NlogN)+ klogN k==Index k
	int findKthLargest(vector<int>& nums, int k); // O(NlogN) - alpha
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	vector<int> nums = { 3,2,3,1,2,4,5,5,6 };
	int k = 4;
	Solution solution;
	cout << solution.findKthLargest(nums, k);

	return 0;
}

int Solution::findKthLargest(vector<int>& nums, int k)
{
	priority_queue<int, vector<int>, greater<int>> KthLargestElements;
	for (int i = 0; i < k; i++)
	{
		KthLargestElements.push(nums[i]);
	}
	for (int i = k; i < (int)nums.size(); i++)
	{
		if (KthLargestElements.top() <= nums[i])
		{
			KthLargestElements.pop();
			KthLargestElements.push(nums[i]);
		}
	}
	return KthLargestElements.top();
}

int Solution::SortSolution(vector<int>& nums, int k)
{
	sort(nums.begin(), nums.end());
	return nums[nums.size() - k];
}

int Solution::PQSolution(vector<int>& nums, int k)
{
	priority_queue<int> KthLargestElements;
	for (int num : nums)
	{
		KthLargestElements.push(num);
	}
	while (k > 1)
	{
		k--;
		KthLargestElements.pop();
	}
	return KthLargestElements.top();
}

