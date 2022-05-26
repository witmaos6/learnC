// unsigned int n 값을 입력 받았을 때 n의 이진법 표기에서 1의 개수를 구하시오
#include <iostream>
#include <cstdint>
#include <string>
#include <bitset>
using namespace std;

class Solution {
private:
	int theNumberOfOne = 0;
public:
	int hammingWeight(uint32_t n);
	int hammingWeightToString(uint32_t n);
	int hammingWeightUseBitset(uint32_t n);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	uint32_t number = 421;
	
	Solution solution;
	cout << solution.hammingWeight(number);

	return 0;
}

int Solution::hammingWeight(uint32_t n)
{
	if (n % 2 == 1)
	{
		theNumberOfOne++;
	}
	n /= 2;

	if (n > 0)hammingWeight(n);
	return theNumberOfOne;
}

int Solution::hammingWeightToString(uint32_t n)
{
	string number = to_string(n);
	for (unsigned int i = 0; i < number.size(); i++)
	{
		if (number[i] == 1)
		{
			theNumberOfOne++;
		}
	}

	return theNumberOfOne;
}

int Solution::hammingWeightUseBitset(uint32_t n)
{
	bitset<32> bs1(n);
	cout << bs1;
	return 0;
}
// Input: n = 00000000000000000000000000001011 이따구로 되어 있어서 이해를 잘 못해 다양한 방법으로 시도했다.
// n은 unsigned int 값이고 이를 이진법으로 변환한 뒤 1의 개수를 구하면 되는 문제다.
// while문을 이용해서 n을 이진법으로 바꿔보기도 했고 재귀함수를 써보기도 했다.
//결과적으로 n%2값을 int binary에 저장한 뒤 1과 비교한 후 theNumberOfOne++; 작업을 하는 것보다 n%2를 바로 1과 비교한게 가장 빨랐다.
//다만 클린코드 관점에서 생각했을 때 이게 좋은 방식인지는 모르겠다.
