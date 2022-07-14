// PhoneNumber가 있다. digits가 주어지면 PhoneNumber에 있는 가능한 조합을 순서에 상관없이 출력해라.
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
// 시간 복잡도는 digits의 길이를 N, 숫자의 알파벳 개수를 M이라고 했을 때 (M^N)*N이 된다. M은 최대 4이기 때문에 O((4^N)*N)이다.
// digits의 길이가 일정하다면 for문 중첩으로 풀 수 있었지만 일정하지 않았기 때문에 재귀함수를 사용했다.
// DFS를 어떤식으로 구현해야 할지 모르겠어서 discuss를 참고 했다.
// 인수가 5개나 되서 줄일 필요가 있다.
