class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.size();
        string b = s;
        reverse(b.begin(), b.end());
        int m = b.size();
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        string ans;
        int i = n, j = m;
        while (i != 0 && j != 0)
        {
            if (s[i - 1] == b[j - 1])
            {
                ans += s[i - 1];
                i--;
                j--;
            }
            else
            {
                if (dp[i][j - 1] > dp[i - 1][j])
                    j--;
                else
                    i--;
            }
        }
        return n - ans.size();
    }
};