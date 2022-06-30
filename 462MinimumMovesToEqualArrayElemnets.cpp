// 배열이 주어졌을 때 배열안에 있는 모든 숫자들을 최소한의 연산으로 같게 만든다.
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

int Solution::minMoves2(vector<int>& nums) //O(NlogN) + O(N)
{
	sort(nums.begin(), nums.end()); // O(NlogN)
	int median = nums.size() / 2;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) //O(N)
	{
		sum += abs(nums[median] - nums[i]);
	}
	return sum;
}
// 처음에는 평균값을 구한 후 위치를 조정하여 맞추려고 시도했다.
// 하지만 숫자 n을 기준으로 n보다 큰 숫자와 작은 숫자의 개수만 맞추면 된다는 걸 알아냈고 중간값을 찾아 연산을 해주는 방법을 사용하여 풀었다.
