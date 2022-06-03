// 두개의 문자열 haystack과 needle이 있다. haystack안에 needle 문자열이 포함되엉 있다면 시작되는 위치를 출력하라
#include <iostream>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int iterSize = haystack.size() - needle.size();
		
		if (iterSize == 0 && haystack == needle)
		{
			return 1;
		}

		for (int i = 0; i <= iterSize; i++)
		{
			if (haystack[i] == needle[0])
			{
				if (haystack.substr(i, needle.size()) == needle)
				{
					return i;
				}
			}
		}

		return -1;
	}
};

int main(void)
{
	string haystack = "abc";
	string needle = "c";

	Solution solution;
	cout << solution.strStr(haystack, needle);

	return 0;
}
//if (iterSize == 0 && haystack == needle){return 1;} 이 문단이 없을 때 실행 속도는 3ms, 메모리는 6.5MB였다.
//위 문단을 추가 했을 때 실행 속도는 0ms, 메모리는 6.4MB를 사용했다. 문단을 추가했는데 메모리는 오히려 절약되고 속도는 빨라져 신기해서 깃허브에 추가하려고 한다.
//if (haystack[i] == needle[0]) 이 조건문을 추가 했을 때 메모리 0.1MB가 더 절약됨, 똑같은 코드라도 제출 할 때마다 시간과 메모리가 달라져 유의미한지는 
