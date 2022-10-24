#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int ArrSize = 0;
	int MaximumLength = 0;

	vector<vector<int>> ArrToCharacter;
	int maxLength(vector<string>& arr);
	vector<int> ToCharacter(string& s);
	void DFS(int Index, vector<int> CurrentCombi);
	bool bHaveDuplication(vector<int>& arr);

	int maxLengthUseBitset(vector<string>& arr);
	bool bHaveDuplicationBit(int& BitsetSize, string& s);
	bool bHaveDuplicationBit(bitset<26>& a, bitset<26>& c);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution solution;
	vector<string> Arr = { "a", "abc", "d", "de", "def" };

	cout << solution.maxLength(Arr);

	return 0;
}

int Solution::maxLength(vector<string>& arr)
{
	ArrSize = static_cast<int>(arr.size());
	ArrToCharacter.reserve(ArrSize);

	for (string& s : arr)
	{
		vector<int> Temp = ToCharacter(s);
		if (!Temp.empty())
		{
			ArrToCharacter.emplace_back(Temp);
		}
	}

	ArrSize = static_cast<int>(ArrToCharacter.size());
	for (int i = 0; i < ArrSize; i++)
	{
		DFS(i + 1, ArrToCharacter[i]);
	}

	return MaximumLength;
}

vector<int> Solution::ToCharacter(string& s)
{
	vector<int> Character(26);

	int Count = 0;
	for (char& c : s)
	{
		if (Character[c - 'a'] == 1)
		{
			return {};
		}
		Character[c - 'a'] = 1;
		Count++;
	}
	MaximumLength = max(MaximumLength, Count);

	return Character;
}

void Solution::DFS(int Index, vector<int> CurrentCombi)
{
	if (bHaveDuplication(CurrentCombi))
	{
		return;
	}
	for (int i = Index; i < ArrSize; i++)
	{
		vector<int> NewCombi = CurrentCombi;
		int Count = 0;
		for (int j = 0; j < 26; j++)
		{
			NewCombi[j] += ArrToCharacter[i][j];
			if (NewCombi[j] == 1)
			{
				Count++;
			}
		}
		MaximumLength = max(MaximumLength, Count);
		DFS(i + 1, NewCombi);
	}
}

bool Solution::bHaveDuplication(vector<int>& arr)
{
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > 1)
		{
			return true;
		}
	}
	return false;
}

int Solution::maxLengthUseBitset(vector<string>& arr)
{
	vector<bitset<26>> DP = { bitset<26>() };

	int MaximumLength = 0;

	for (string& s : arr) {
		bitset<26> a;
		for (char& c : s)
		{
			a.set(c - 'a');
		}

		int n = static_cast<int>(a.count());
		if (!bHaveDuplicationBit(n, s))
		{
			int DPSize = static_cast<int>(DP.size());
			for (int i = DPSize - 1; i >= 0; --i)
			{
				bitset<26> c = DP[i];
				if (!bHaveDuplicationBit(c, a))
				{
					DP.push_back(c | a);
					MaximumLength = max(MaximumLength, static_cast<int>(c.count()) + n);
				}
			}
		}
	}
	return MaximumLength;
}

bool Solution::bHaveDuplicationBit(int& BitsetSize, string& s)
{
	return BitsetSize < s.size() ? true : false;
}

bool Solution::bHaveDuplicationBit(bitset<26>& a, bitset<26>& c)
{
	return (a & c).any();
}
