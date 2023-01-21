class Solution {
    vector<string> ValidIP;
public:
    vector<string> restoreIpAddresses(string s)
    {
        StringSize = static_cast<int>(s.size());

        if(StringSize >= 13)
        {
            return ValidIP;
        }

        DFS(s, 0, "", 0);

        return ValidIP;
    }
private:
    int StringSize = 0;
    const char Dot = '.';
    const int MaxDigit = 255;

    void DFS(const string& s, int Index, string NewString, int DotCount)
    {
        if(DotCount == 3)
        {
            string LastPart = s.substr(Index);
            if(bIsValidIP(LastPart))
            {
                NewString += LastPart;
                ValidIP.push_back(NewString);
            }
            return;
        }

        for(int i = 1; i <= 3; i++)
        {
            string NewPart = s.substr(Index, i);
            if(bIsValidIP(NewPart))
            {
                NewString += NewPart + Dot;
                DFS(s, Index + i, NewString, DotCount + 1);
            }
        }
    }

    bool bIsValidIP(const string& s)
    {
        size_t SLength = s.length();
        if(SLength == 1)
        {
            return true;
        }
        
        int Digit = stoi(s);
        if(SLength > 3 || s[0] == '0' || (Digit > MaxDigit))
        {
            return false;
        }

        return true;
    }
};
