#include <iostream>
using namespace std;

class Solution {
private:
	int ANumberThatComesOutInAnInfiniteCycle = 89;
public:
	bool isHappy(int n);
	int SeparateOfDigitsAndTheSumOfSquares(int n);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int CheckingHappyNunber = 342256;
	Solution solution;
	cout << solution.isHappy(CheckingHappyNunber);

	return 0;
}

bool Solution::isHappy(int n)
{
	while (n != 1)
	{
		if (n == ANumberThatComesOutInAnInfiniteCycle)
		{
			return false;
		}
		n = SeparateOfDigitsAndTheSumOfSquares(n);
	}
	return true;
}

int Solution::SeparateOfDigitsAndTheSumOfSquares(int n)
{
	int SumOfSquare = 0;
	while (n > 0)
	{
		int temp = n % 10;
		SumOfSquare += temp * temp;
		n /= 10;
	}
	return SumOfSquare;
}
