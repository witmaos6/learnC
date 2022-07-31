#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> wordSubsets(vector<string>& words1, vector<string>& words2);
	unordered_map<char, int> countSubset(string& words);

	vector<string> wordSubsetsUseVector(vector<string>& words1, vector<string>& words2);
	vector<int> countSubsetUseVector(string& words);
	void printVector(vector<string>& Subset);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<string> Words1 = { "amazon","apple","facebook","google","leetcode" };
	vector<string> Words2 = { "e","l" };
	Solution solution;

	vector<string> UniversalString = solution.wordSubsetsUseVector(Words1, Words2);
	solution.printVector(UniversalString);

	return 0;
}

vector<string> Solution::wordSubsets(vector<string>& words1, vector<string>& words2)
{
	vector<string> UniversalString;
	UniversalString.reserve(size(words1));
	unordered_map<char, int> Subset;

	for (string& word : words2)
	{
		unordered_map<char, int> temp = countSubset(word);
		for (char& c : word)
		{
			Subset[c] = max(temp[c], Subset[c]);
		}
	}

	for (string& word : words1)
	{
		unordered_map<char, int> countSubsetWords1 = countSubset(word);
		bool isSubset = true;
		for (auto& c : Subset)
		{
			if (countSubsetWords1.find(c.first) == countSubsetWords1.end())
			{
				isSubset = false;
				break;
			}
			else if (countSubsetWords1[c.first] < Subset[c.first])
			{
				isSubset = false;
				break;
			}
		}
		if (isSubset)
		{
			UniversalString.push_back(word);
		}
	}
	return UniversalString;
}

unordered_map<char, int> Solution::countSubset(string& words)
{
	unordered_map<char, int> subset;
	for (char& word : words)
	{
		if (subset.find(word) != subset.end())
		{
			subset[word]++;
		}
		else
		{
			subset[word] = 1;
		}
	}
	return subset;
}

vector<string> Solution::wordSubsetsUseVector(vector<string>& words1, vector<string>& words2)
{
	vector<string> UniversalString;
	UniversalString.reserve(size(words1));
	vector<int> Subset(26);

	for (string& word : words2)
	{
		vector<int> Temp = countSubsetUseVector(word);
		for (int i = 0; i < 26; i++)
		{
			Subset[i] = max(Temp[i], Subset[i]);
		}
	}

	for (string& word : words1)
	{
		vector<int> Temp = countSubsetUseVector(word);
		bool isValid = true;
		for (int i = 0; i < 26; i++)
		{
			if (Temp[i] < Subset[i])
			{
				isValid = false;
				break;
			}
		}
		if (isValid)
		{
			UniversalString.push_back(word);
		}
	}
	return UniversalString;
}

vector<int> Solution::countSubsetUseVector(string& words)
{
	vector<int> subset(26);
	for (char& c : words)
	{
		subset[c - 'a']++;
	}
	return subset;
}

void Solution::printVector(vector<string>& Subset)
{
	for (string str : Subset)
	{
		cout << str << ' ';
	}
}
// 문제의 조건이 명확하지 않아 좀 해맸다.
// words1이 words2에 있는 문자열을 모두 포함하는지 찾는 문제인데 개수도 맞아야 한다.
// 그런데 words2가 {"a","aa"} 이런식으로 되어있다면 aa만 취급해도 된다. -> 이부분 때문에 머리가 좀 아팠다.
// 처음에는 unordered_map으로 접근했는데 순회를 해야하는 문제라 그런지 실행속도가 상당히 느렸다.
