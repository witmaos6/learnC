// string s와 string 배열 words가 주어진다. words안에 있는 s의 subsequence의 개수를 반환하라
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	unsigned int sSize = 1;
	map<string, int> DP;

	int numMatchingSubseq(string s, vector<string>& words);
	int CheckSubsequence(string& s, string& word, unsigned int& wordSize);
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string S = "dsahjpjauf";
	vector<string> Words = { "ahjpjau","ja","ahbwzgqnuk","tnmlanowax" };

	Solution solution;
	cout << solution.numMatchingSubseq(S, Words);

	return 0;
}

int Solution::numMatchingSubseq(string s, vector<string>& words)
{
	int TheNumberOfSubsequence = 0;
	sSize = size(s);

	for (string& word : words) // O(N) N==size(words)
	{
		unsigned int WordSize = size(word);
		if (WordSize > sSize)
		{
			continue;
		}
		if (DP.count(word) == 1)
		{
			TheNumberOfSubsequence += DP[word];
		}
		else
		{
			TheNumberOfSubsequence += CheckSubsequence(s, word, WordSize);
		}
	}
	return TheNumberOfSubsequence;
}

int Solution::CheckSubsequence(string& s, string& word, unsigned int& wordSize)
{
	unsigned int sPoint = 0;
	unsigned int WordPoint = 0;

	while (sPoint < sSize && WordPoint < wordSize) // O(N or M) N은 sSizes M은 wordSize이다. worst case는 더 큰 쪽
	{
		if (s[sPoint] == word[WordPoint])
		{
			WordPoint++;
		}
		sPoint++;
	}
	if (WordPoint == wordSize)
	{
		DP[word] = 1;
		return 1;
	}
	DP[word] = 0;
	return 0;
}
// map을 이용한 메모리제이션으로 문제를 풀었다.
// 최종 시간복잡도는 O(N)+O(M)이다. N == size(words) M = sSize > wordSize ? sSize : wordSize; 이다
