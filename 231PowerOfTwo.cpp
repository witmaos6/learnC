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
