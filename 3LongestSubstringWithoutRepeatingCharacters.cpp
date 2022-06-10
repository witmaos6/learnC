//중복된 문자가 없는 가장 긴 문자열을 찾는 문제이다.
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s); // O(N) N==s.size()
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
//중복된 문자가 없는 문자열을 찾아야 하기 때문에 set을 이용해봤다.
//사이트 기준으로 속도도 느린편이고 메모리 사용량도 많은 편이다.
//int[256]을 이용하여 속도도 빠르고 메모리 사용량도 작은 알고리즘을 찾긴했다.
