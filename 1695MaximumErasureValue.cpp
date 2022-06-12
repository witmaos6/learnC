#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums);
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

	vector<int> nums = { 187,470,25,436,538,809,441,167,477,110,275,133,666,345,411,459,490,266,987,965,429,166,809,340,467,318,125,165,809,610,31,585,970,306,42,189,169,743,78,810,70,382,367,490,787,670,476,278,775,673,299,19,893,817,971,458,409,886,434 };
    Solution solution;
	cout << solution.maximumUniqueSubarray(nums);

    return 0;
}

int Solution::maximumUniqueSubarray(vector<int>& nums)
{
    int left = 0;
    int right = 1;
    int SumOfSubarray = nums[0];
    int MaximumSubarray = 0;
    set<int> Subarray = { nums[0] };

	while (right < (int)nums.size())
    {
        while(Subarray.find(nums[right])!=end(Subarray))
        {
			Subarray.erase(nums[left]);
			SumOfSubarray -= nums[left];
			left++;
        }
		Subarray.insert(nums[right]);
		SumOfSubarray += nums[right];
		right++;
        MaximumSubarray = max(MaximumSubarray, SumOfSubarray);
    }

    return MaximumSubarray;
}
