#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
	bool equationsPossible(vector<string>& equations);
	int Find(vector<int>& arr, int x);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solution solution;
	vector<string> Equations = { "c!=e","a==b", "b==a", "c==d", "c==a" };
	cout << solution.equationsPossible(Equations);

	return 0;
}

bool Solution::equationsPossible(vector<string>& equations)
{
	vector<int> UnionFind(26);
	for (int i = 0; i < 26; i++)
	{
		UnionFind[i] = i;
	}
	for (string& s : equations)
	{
		if (s[1] == '=')
		{
			int s0 = Find(UnionFind, s[0] - 'a');
			int s3 = Find(UnionFind, s[3] - 'a');
			UnionFind[s0] = s3;
		}
	}
	for (string& s : equations)
	{
		if (s[1] == '!' && Find(UnionFind, s[0] - 'a') == Find(UnionFind, s[3] - 'a'))
		{
			return false;
		}
	}
	return true;
}

int Solution::Find(vector<int>& arr, int x)
{
	if (x != arr[x])
	{
		arr[x] = Find(arr, arr[x]);
	}
	return arr[x];
}
