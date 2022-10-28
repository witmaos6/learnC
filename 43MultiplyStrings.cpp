#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int stringToINT = '0';
	string multiply(string num1, string num2);
	vector<int> StringToIntVector(string& s, int& sSize);
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

	if (Num1Size + Num2Size <= 19)
	{
		return to_string(stoull(num1) * stoull(num2));
	}

	vector<int> ToNum1 = StringToIntVector(num1, Num1Size);
	vector<int> ToNum2 = StringToIntVector(num2, Num2Size);

	vector<int> Multiplcation(Num1Size + Num2Size);

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
	while (Multiplcation[i] == 0)
	{
		i++;
	}
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
