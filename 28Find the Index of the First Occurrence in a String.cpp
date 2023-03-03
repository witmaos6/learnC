// haystack에서 needle 문자열이 있는지 찾아라. (needle이 haystack의 부분문자열인지 찾아라.) 부분문자열이 아니라면 -1을 맞다면 haystack의 begin index를 반환하라.

class Solution {
    int HayLength = 0;
    int NeedleLength = 0;
public:
    int strStr(string haystack, string needle) 
    {
        HayLength = static_cast<int>(haystack.size());
        NeedleLength = static_cast<int>(needle.size());

        vector<int> KMP = SetKMP(needle, NeedleLength);

        int HIndex = 0, NIndex = 0;
        while(HIndex < HayLength)
        {
            if(haystack[HIndex] == needle[NIndex])
            {
                HIndex++;
                NIndex++;
                if(NIndex == NeedleLength)
                {
                    return HIndex - NIndex;
                }
            }
            else if(HIndex < HayLength && haystack[HIndex] != needle[NIndex])
            {
                if(NIndex > 0)
                {
                    NIndex = KMP[NIndex - 1];
                }
                else
                {
                    HIndex++;
                }
            }
        }

        return -1;
    }

private:
    vector<int> SetKMP(const string& needle, const int& Size)
    {
        vector<int> Set(Size);
        int Length = 0;
        int i = 1;

        while(i < Size)
        {
            if(needle[i] == needle[Length])
            {
                Length++;
                Set[i] = Length;
                i++;
            }
            else
            {
                if(Length > 0)
                {
                    Length = Set[Length - 1];
                }
                else
                {
                    Set[i] = 0;
                    i++;
                }
            }
        }

        return Set;
    }
};

// bruteforce로 풀어보고 KMP알고리즘으로도 풀어봤다.
// 근데 KMP알고리즘은 접두사와 접미사가 동일한 경우에만 유용한 알고리즘인것 같은데 경우에 따라서 bruteforce가 더 나을 수도 있을 거라는 생각이 든다.
// 채점 결과로는 KMP가 더 느리다.
