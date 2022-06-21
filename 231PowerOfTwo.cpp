// 정수 n이 주어졌을 때 n==2^x 라면 true 아니면 false를 반환하라
#include <iostream>
using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n);
	int CountBitset(int n);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n = 1;
	Solution solution;
	cout << solution.isPowerOfTwo(n);

	return 0;
}

bool Solution::isPowerOfTwo(int n)
{
	return n > 0 && not (n & n - 1);
	
}

int Solution::CountBitset(int n)
{
	int CountOfBitset = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
	CountOfBitset = ((CountOfBitset + (CountOfBitset >> 3)) & 030707070707) % 63;
	return CountOfBitset;
}
// 루프문 없이 문제를 해결해야 돼서 어떻게 해야할지 고민이 많이됐다.
// 여러가지 방법을 찾다가 비트를 통해서 구하는 방법을 떠올렸다.
// CountBitset으로 1비트 개수를 구한 뒤 개수가1이라면 true 아니라면 false를 반환하는 방법도 있었지만 더 좋은 방법도 있었다. isPowerOfTwo가 그것이다.
