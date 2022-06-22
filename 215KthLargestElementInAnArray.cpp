// 배열이 주어지면 k번째로 큰 원소를 반환하라
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int SortSolution(vector<int>& nums, int k); // O(NlogN+N) N==nums.size()
	int PQSolution(vector<int>& nums, int k); //O(NlogN+klogN) k==Index k
	int findKthLargest(vector<int>& nums, int k); // O(klogN + N-klogN)
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
	priority_queue<int, vector<int>> KthLargestElements;
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
// SortSolution은 정렬한 후 k번째 원소위치를 찾아서 반환하는 간단한 알고리즘이다.
// PQSolution은 우선순위 큐를 사용하였다. 모든 원소를 push한 후에 k-1만큼 pop을 하기 때문에 sort보다 시간이 더 오래걸린다.
// 마지막으로 첫번 째 함수도 우선순위큐를 사용하였지만 큐의 크기를 k만큼 고정하여 top과 이후에 원소들의 크기를 비교하고 push를 할지 결정하기 때문에 삽입 삭제 연산 횟수를 줄일 수 있다.
// 물론 최악의 경우에는 PQSolution과 똑같긴 하다.
