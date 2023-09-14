class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.empty())
            return true;
        int x = 0;
        for (char c : t)
        {
            if (c == s[x])
                x++;
            if (x == s.size())
                return true;
        }
        return false;
    }
};