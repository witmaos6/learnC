// 두개의 string num1, num2의 곱셉결과를 string으로 반환하라.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string multiply(string num1, string num2);
	vector<int> StringToIntVector(string& s, int& sSize);
	void LessThanMaxDigit(size_t& i, vector<int>& Result);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution solution;
	string Num1 = "123", Num2 = "456";
	cout << solution.multiply(Num1, Num2);

	return 0;
}

string Solution::multiply(string num1, string num2)
{
	int Num1Size = static_cast<int>(num1.size());
	int Num2Size = static_cast<int>(num2.size());
	int MaxDigitsize = Num1Size + Num2Size;

	vector<int> ToNum1 = StringToIntVector(num1, Num1Size);
	vector<int> ToNum2 = StringToIntVector(num2, Num2Size);

	vector<int> Multiplcation(MaxDigitsize);

	for (int i = Num1Size - 1; i >= 0; i--)
	{
		for (int j = Num2Size - 1; j >= 0; j--)
		{
			Multiplcation[i + j + 1] += ToNum1[i] * ToNum2[j];
			Multiplcation[i + j] += Multiplcation[i + j + 1] / 10;
			Multiplcation[i + j + 1] %= 10;
		}
	}

	size_t i = 0;
	string Result = "";

	LessThanMaxDigit(i, Multiplcation);
	
	while (i < Multiplcation.size())
	{
		Result += to_string(Multiplcation[i]);
		i++;
	}

	return Result;
}

vector<int> Solution::StringToIntVector(string& s, int& sSize)
{
	vector<int> ToIntVector(sSize);

	for (int i = 0; i < sSize; i++)
	{
		ToIntVector[i] = s[i] - '0';
	}
	return ToIntVector;
}

void Solution::LessThanMaxDigit(size_t& i, vector<int>& Result)
{
	while (Result[i] == 0)
	{
		i++;
	}
}

// ull(unsigned long long)의 최대값은 1800경 정도 된다. 그래서 그 이하의 자리수는 그냥 ull값으로 전환->곱셈->string 으로 다시 전환 후 반환 알고리즘을 사용했다.
// ull로 표현이 불가능한 숫자들은 계산하면서 동시에 자리수를 고려하며 계산한 뒤 적절한 위치에 넣어주면 됐다. 자리수를 파악하는 것은 곱셈의 특성을 알면 쉽다.
