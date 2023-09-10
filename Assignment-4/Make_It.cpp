#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int dp[N];
bool make(int s, int n)
{
    if (s == n)
        return true;
    if (s > n)
        return false;
    if (dp[s] != -1)
        return dp[s];
    bool op1 = make(s + 3, n);
    bool op2 = make(s * 2, n);
    return dp[s] = op1 || op2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i <= N; i++)
        {
            dp[i] = -1;
        }
        if (make(1, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}