// 중복된 정수를 최소 개수로 제거하여 vector의 크기를 절반이하로 
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
	typedef int Num;
	typedef int TheNumberOfNum;
	static const int MaxValue = 100001;
	int minSetSize(vector<int>& arr);
	int MinSetSizeUseBucketSort(vector<int>& arr);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution solution;
	vector<int> Arr = { 3,3,3,3,5,5,5,2,2,7 };
	cout << solution.minSetSize(Arr) << '\n';
	cout << solution.MinSetSizeUseBucketSort(Arr);

	return 0;
}

int Solution::minSetSize(vector<int>& arr)
{
	map<int, int>Subset;
	priority_queue<int> pq;
	int ArrHalfSize = static_cast<int>(size(arr) + 1) >> 1;

	for (int& num : arr) // O(NlogN)
	{
		if (Subset.find(num) == Subset.end())
		{
			Subset[num] = 1;
		}
		else
		{
			Subset[num]++;
		}
	}
	for (auto& e : Subset) // O(NlogN)
	{
		pq.push(e.second);
	}
	int CountingSubset = 0;
	while (!pq.empty()) // O(NlogN)
	{
		ArrHalfSize -= pq.top();
		CountingSubset++;
		if (ArrHalfSize < 0)
		{
			return CountingSubset;
		}
	}
	return static_cast<int>(size(Subset));
}

int Solution::MinSetSizeUseBucketSort(vector<int>& arr)
{
	vector<int>Frequency(MaxValue);
	vector<int>Bucket(MaxValue);
	int CountingSubsetDelete = 0;
	int HalfSize = static_cast<int>(size(arr) + 1) >> 1;

	for (auto& num : arr) // O(N)
	{
		Frequency[num]++;
	}
	for (int i = 1; i < MaxValue; i++) // O(N)
	{
		if (Frequency[i])
		{
			Bucket[Frequency[i]]++;
		}
	}
	for (int f = MaxValue - 1; HalfSize > 0; f--) // O(N)
	{
		while (Bucket[f] > 0 && HalfSize > 0)
		{
			HalfSize -= f;
			Bucket[f]--;
			CountingSubsetDelete++;
		}
	}
	return CountingSubsetDelete;
}
// 첫번째 방식은 map을 이용해서 중복된 정수와 개수를 찾아내고 우선순위큐를 이용해서 중복된 정수의 개수를 큰 순서로 빼는 것이다.
// 두번째 방식은 vector가 랜덤액세스가 빠르다는 성질을 이용한 것이다. 속도는 빨라도 메모리 낭비는 심할것이라 생각했는데 메모리 사용량도 더 낮았다.
// 첫번째 방식의 시간과 메모리 사용량은 431ms 80mb고 두번째 방식은 104ms 56mb이다.
