// 배열이 주어졌을 때 가장 긴 연속 수열의 길이를 구하여라
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
	unordered_set<int> ToSearchSet(nums.begin(), nums.end()); // O(N)
	int LengthTheLongest = 0;
	for (const int& num : ToSearchSet) //O(N)
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
// 가장빠른 방법은 정렬을 한 뒤 연속 수열을 찾는 것이었다.
// 내가 푼 방식은 unordered_set에 입력값을 넣고 연속수열을 찾는 것이었다.
// unordered_set은 입력과 탐색이 O(1)의 속도로 상당히 빠르기 때문에 가장 적합하다고 생각했다.
// O(N)시간 안에 해결해야 하는 문제라서 정렬 없이 한번의 탐색으로 해야 된다 생각했는데 뒷통수 맞은 기분이었다.
