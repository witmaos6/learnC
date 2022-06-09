#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target); //이진탐색 O(NlogN) N==numbers.size()
	vector<int> twoSumSecondSolution(vector<int>& numbers, int target); // 선형탐색 O(N) N==numbers.size()
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
} // 중복된 인덱스를 반환하는 경우도 있고 NlogN의 시간복잡도를 가지기 때문에 시간초과가 나는 경우도 있음

vector<int> Solution::twoSumSecondSolution(vector<int>& numbers, int target)
{
	int FirstTarget = 0;
	int LastTarget = numbers.size() - 1;
	int sum = numbers[FirstTarget] + numbers[LastTarget];

	while (FirstTarget < LastTarget)
	{
		sum = numbers[FirstTarget] + numbers[LastTarget];
		if(sum == target)
		{
			break;
		}
		else if (sum > target)
		{
			LastTarget--;
		}
		else if (sum < target)
		{
			FirstTarget++;
		}
	}
	return { FirstTarget + 1, LastTarget + 1 };
} // 오름차순 정렬이기 때문에 맨 왼쪽과 오른쪽 값을 덧셈하면서 실행
//sum 연산을 하지 않을 경우 실행속도가 빠르지만 읽기는 불편해진다.
