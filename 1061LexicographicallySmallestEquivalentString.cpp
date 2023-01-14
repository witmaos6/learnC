// Union find 알고리즘 문제
class Solution {
    vector<char> Table;
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        SLength = static_cast<int>(s1.size());
        BaseSLength = static_cast<int>(baseStr.size());
        Table.resize(26, Space);
        SetTable(s1, s2);

        for(char& c : baseStr)
        {
            char FindChar = Find(c);
            c = FindChar;
        }
        
        return baseStr;
    }
private:
    int SLength = 0;
    int BaseSLength = 0;
    const char Space = ' ';

    void SetTable(string& s1, string& s2)
    {
        for(int i = 0; i < SLength; i++)
        {
            char c1 = s1[i];
            char c2 = s2[i];
            char FindChar1 = Find(c1);
            char FindChar2 = Find(c2);

            if(FindChar1 != FindChar2)
            {
                if(FindChar1 > FindChar2)
                {
                    swap(c1, c2);
                    swap(FindChar1, FindChar2);
                }
                Table[FindChar2 - 'a'] = Table[FindChar1 - 'a'];
                Find(c1);
                Find(c2);
            }
        }
    }

    char Find(char c)
    {
        if(Table[c - 'a'] == Space)
        {
            Table[c - 'a'] = c;
            return c;
        }
        while(Table[c - 'a'] != c)
        {
            Table[c - 'a'] = Table[Table[c - 'a'] - 'a'];
            c = Table[c - 'a'];
        }
        return c;
    }
};

// UnionFind 알고리즘 문제다. 수업 때 배우긴 했으나 워낙 안쓰던 알고리즘이라 그런지 떠올릴 수가 없었다.
