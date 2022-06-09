#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target);
	vector<int> twoSumSecondSolution(vector<int>& numbers, int target);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	vector<int> numbers = { -1,0,3,5,7,11,15,18,19,23 };
	int target = 10;
	
	Solution solution;
	numbers = solution.twoSum(numbers, target);
	cout << numbers[0] << ' ' << numbers[1];

	return 0;
}

vector<int> Solution::twoSum(vector<int>& numbers, int target)
{
	for (int TargetLocation = 0; TargetLocation < numbers.size(); TargetLocation++)
	{
		vector<int>::iterator TargetSumLocation = find(numbers.begin(), numbers.end(), target - numbers[TargetLocation]);
		if (TargetSumLocation != numbers.end())
		{
			return { TargetLocation + 1, distance(numbers.begin(), TargetSumLocation) + 1};
		}
	}
	return {};
}

vector<int> Solution::twoSumSecondSolution(vector<int>& numbers, int target)
{
	int FirstTarget = 0;
	int LastTarget = numbers.size() - 1;
	int sum = numbers[FirstTarget] + numbers[LastTarget];

	while (sum != target)
	{
		sum = numbers[FirstTarget] + numbers[LastTarget];
		if (sum > target)
		{
			LastTarget--;
		}
		else if (sum < target)
		{
			FirstTarget++;
		}
	}
	return { FirstTarget + 1, LastTarget + 1 };
}