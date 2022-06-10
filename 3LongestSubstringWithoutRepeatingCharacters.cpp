#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	string SearchString = "abcabcbb";

	Solution solution;
	cout << solution.lengthOfLongestSubstring(SearchString);

	return 0;
}

int Solution::lengthOfLongestSubstring(string s)
{
	if (s.size() == 0) {
		return 0;
	}

	set<char> Substring;
	int MaxSize = 0;
	int EraseS = 0;
	int inputS = 0;

	while (inputS < (int)s.size())
	{
		if (Substring.count(s[inputS]) == 0)
		{
			Substring.insert(s[inputS]);
			MaxSize = max(MaxSize, (int)Substring.size());
			inputS++;
		}
		else
		{
			Substring.erase(s[EraseS]);
			EraseS++;
		}
	}
	return MaxSize;
}
