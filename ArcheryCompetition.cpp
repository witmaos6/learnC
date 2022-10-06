#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> answer = { -1 };
	int MaxDifferenceScore = 0;

	vector<int> LionScore(int n, vector<int> info);
	void Try(int n, vector<int>& info, vector<int>& Lion, int TryIndex);
	void CalculateScore(vector<int>& info, vector<int>& Lion);
	bool bAreMoreArrowsOnTheSmallScore(vector<int>& Lion);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution solution;
	int n = 5;
	vector<int> Info = { 2,1,1,1,0,0,0,0,0,0,0 };
	vector<int> LionTry = solution.LionScore(n, Info);

	for (int& i : LionTry)
	{
		cout << i << ' ';
	}

	return 0;
}

vector<int> Solution::LionScore(int n, vector<int> info) {
	vector<int> Lion(11);
	Try(n, info, Lion, 0);

	return answer;
}

void Solution::Try(int n, vector<int>& info, vector<int>& Lion, int TryIndex)
{
	if (TryIndex == 11 || n == 0) {
		Lion[10] += n;
		CalculateScore(info, Lion);
		Lion[10] -= n;
		return;
	}

	if (info[TryIndex] < n) {
		Lion[TryIndex] += info[TryIndex] + 1;
		Try(n - info[TryIndex] - 1, info, Lion, TryIndex + 1);
		Lion[TryIndex] -= info[TryIndex] + 1;
	}

	Try(n, info, Lion, TryIndex + 1);
}

void Solution::CalculateScore(vector<int>& info, vector<int>& Lion)
{
	int ApeachScore = 0;
	int LionScore = 0;
	for (int i = 0; i < 11; i++)
	{
		if (info[i] < Lion[i])
		{
			LionScore += 10 - i;
		}
		else if(info[i] > 0)
		{
			ApeachScore += 10 - i;
		}
	}
	int DifferenceScore = LionScore - ApeachScore;
	if (DifferenceScore > 0 && DifferenceScore >= MaxDifferenceScore)
	{
		if (MaxDifferenceScore == DifferenceScore && !bAreMoreArrowsOnTheSmallScore(Lion))
		{
			return;
		}
		MaxDifferenceScore = DifferenceScore;
		answer = Lion;
	}
}

bool Solution::bAreMoreArrowsOnTheSmallScore(vector<int>& Lion)
{
	for (int i = 10; i >= 0; i--) {
		if (Lion[i] > answer[i])
		{
			return true;
		}
		else if (Lion[i] < answer[i])
		{
			return false;
		}
	}
}