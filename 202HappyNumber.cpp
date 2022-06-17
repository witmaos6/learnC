// 양의 정수 n이 주어지면 각 자리수의 제곱의 합이 1이 나오거나 무한대로 순환할 때까지 반복하고 1이나오면 true 무한순환이나온다면 false를 반환하라
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
// 컴퓨터의 랜덤에 대해서 배울 때 계산식을 이용하게되면 특정 패턴이 발생해 계산을 통한 랜덤이 불가능하다는 이야기를 들은적이 있다.
// 자리수의 제곱의 합도 마찬가지로 무한 순환하게 된다면 특정 값에 도달할 것이라 생각했는데 89라는 숫자가 있다는 글을 보고 ANumberThatComesOutInAnInfiniteCycle을 넣었다.
// 문제를 처음 풀 때는 brute force로 n의 값을 set에 집어넣고 find하는 방식으로 풀었는데 시간이 상당히 걸렸다.
