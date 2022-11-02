#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
public:
	char Gene[4] = { 'A','C','G','T' };

	int minMutation(string start, string end, vector<string>& bank);
	void NewBFS(unordered_set<string>& Mutation, queue<string>& BFS, string& s);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution solution;
	string Start = "AACCTTGG", End = "AATTCCGG";
	vector<string> Bank = { "AATTCCGG", "AACCTGGG", "AACCCCGG", "AACCTACC" };
	cout << solution.minMutation(Start, End, Bank);

	return 0;
}

int Solution::minMutation(string start, string end, vector<string>& bank)
{
	unordered_set<string> ValidMutation{ bank.begin(), bank.end() };
	if (ValidMutation.find(end) == ValidMutation.end())
	{
		return -1;
	}
	int NumberOfMutations = 0;
	queue<string> BFS;
	BFS.push(start);

	while (!BFS.empty())
	{
		int BFSSize = static_cast<int>(BFS.size());
		for (int i = 0; i < BFSSize; i++)
		{
			string Current = BFS.front();
			BFS.pop();
			if (Current == end)
			{
				return NumberOfMutations;
			}
			ValidMutation.erase(Current);

			NewBFS(ValidMutation, BFS, Current);
		}
		NumberOfMutations++;
	}

	return -1;
}

void Solution::NewBFS(unordered_set<string>& Mutation, queue<string>& BFS, string& s)
{
	for (int i = 0; i < 8; i++)
	{
		string t = s;
		for (char& gene : Gene)
		{
			t[i] = gene;
			if (Mutation.count(t))
			{
				BFS.push(t);
			}
		}
	}
}
