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
	int ArrHalfSize = static_cast<int>(size(arr)) / 2;

	for (int& num : arr)
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
	for (auto& e : Subset)
	{
		pq.push(e.second);
	}
	int CountingSubset = 0;
	while (!pq.empty())
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

	for (auto& num : arr)
	{
		Frequency[num]++;
	}
	for (int i = 1; i < MaxValue; i++)
	{
		if (Frequency[i])
		{
			Bucket[Frequency[i]]++;
		}
	}
	for (int f = MaxValue - 1; HalfSize > 0; f--)
	{
		while (Bucket[f] && HalfSize > 0)
		{
			HalfSize -= f;
			Bucket[f]--;
			CountingSubsetDelete++;
		}
	}
	return CountingSubsetDelete;
}
