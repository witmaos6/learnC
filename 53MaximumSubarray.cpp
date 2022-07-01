#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSum = *max_element(nums.begin(), nums.end());
		int sumSubArray = 0;
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			sumSubArray += nums[i];
			maxSum = max(sumSubArray, maxSum);
			if (sumSubArray < 0)
			{
				sumSubArray = 0;
			}
		}
		return maxSum;
	}
};

int main(void)
{
	vector<int> nums = { 5,4,-1,7,8 };

	Solution solution;
	cout << solution.maxSubArray(nums);

	return 0;
}
//문제: 배열이 주어질 때 가장 높은 합계를 가진 연속 배열의 값을 구해라
//Kadane 알고리즘사용
