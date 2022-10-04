#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int GetNumberOfPrimNumber(int n, int k);
	void ChangeDigits(vector<int>& digits, int n, const int& k);
	long long ChangeDecimal(vector<int>& digits);
	bool bIsPrimeNumber(long long n);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution solution;
	int n = 1000000;
	int k = 2;
	cout << solution.GetNumberOfPrimNumber(n, k);

	return 0;
}

int Solution::GetNumberOfPrimNumber(int n, int k)
{
	int answer = 0;
	vector<int> Number;

	ChangeDigits(Number, n, k);
	reverse(Number.begin(), Number.end());

	int Begin = 0;
	int NumberSize = static_cast<int>(Number.size());

	for (int i = 0; i < NumberSize; i++)
	{
		if (Number[i] == 0 || i == NumberSize - 1)
		{
			vector<int> Change;
			if(Number[i] == 0)
			{
				Change.assign(Number.begin() + Begin, Number.begin() + i);
			}	
			else if(i == NumberSize -1)
			{
				Change.assign(Number.begin() + Begin, Number.end());
			}
			long long Decimal = ChangeDecimal(Change);
			cout << Decimal << '\n';
			if (bIsPrimeNumber(Decimal))
			{
				answer++;
			}
			Begin = i + 1;
		}
	}	
	return answer;
}

void Solution::ChangeDigits(vector<int>& digits, int n, const int& k)
{
	while (n > 0)
	{
		digits.emplace_back(n % k);
		n /= k;
	}
}

long long Solution::ChangeDecimal(vector<int>& digits)
{
	int Decimal = 0;
	for(int& digit : digits)
	{
		Decimal *= 10;
		Decimal += digit;
	}
	return Decimal;
}

bool Solution::bIsPrimeNumber(long long n)
{
	if(n < 2)
	{
		return false;
	}
	long long SquareRoot = static_cast<long long>(floor(sqrt(n)));
	for (long long x = 2; x <= SquareRoot; x++)
	{
		if (n % x == 0)
		{
			return false;
		}
	}
	return true;
}
