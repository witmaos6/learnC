// equations의 방정식이 주어졌을 때 방정식이 모순되면 false를 그렇지 않으면 true를 반환하라
#include <iostream>
#include <vector>
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
// UnionFind와 disjoint set이라는 새로운 개념을 배웠다. disjoint set은 교집합이 없는 서로 다른 집합을 저장하는 자료구조이고 Union Find는 이 자료구조에서 집합을 찾는 방법이다.
// 사이트에서 중요도가 1000번대 이하로 배치되어 있어 개념만 학습하고 넘어간다.
