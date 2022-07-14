#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
	unordered_map<char, string> PhoneNumber{
		{'2',"abc"},
		{'3',"def"},
		{'4',"ghi"},
		{'5',"jkl"},
		{'6',"mno"},
		{'7',"pqrs"},
		{'8',"tuv"},
		{'9',"wxyz"}
	};
public:
	vector<string> letterCombinations(string digits);
	void DFS(int digitPosition, int& DigitsSize, string str, vector<string>& result, string& digits);
	void PrintVector(const vector<string>& vs_vector);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string Digits = "23";

	Solution solution;
	vector<string> LetterCombinations = solution.letterCombinations(Digits);
	solution.PrintVector(LetterCombinations);

	return 0;
}

vector<string> Solution::letterCombinations(string digits)
{
	vector<string> LetterCombinations;
	int DigitsSize = static_cast<int>(size(digits));
	if (DigitsSize == 0)
	{
		return LetterCombinations;
	}
	DFS(0, DigitsSize, "", LetterCombinations, digits);

	return LetterCombinations;

}

void Solution::DFS(int digitPosition, int& DigitsSize, string str, vector<string>& result, string& digits)
{
	if (digitPosition == DigitsSize)
	{
		result.push_back(str);
	}
	else
	{
		string Letters = PhoneNumber[digits[digitPosition]];
		for (int i = 0; i < Letters.size(); i++)
		{
			DFS(digitPosition + 1, DigitsSize, str + Letters[i], result, digits);
		}
	}
}

void Solution::PrintVector(const vector<string>& vs_vector)
{
	for (string s : vs_vector)
	{
		cout << s << ' ';
	}
}
