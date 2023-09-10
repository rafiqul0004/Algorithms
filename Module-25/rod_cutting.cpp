#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int unbound_knapsac(int n, int s, int v[], int w[])
{
    if (s == 0 || n == 0)
        return 0;
    if (dp[n][s] != -1)
        return dp[n][s];
    if (w[n - 1] <= s)
    {
        int op1 = v[n - 1] + unbound_knapsac(n, s - w[n - 1], v, w);
        int op2 = unbound_knapsac(n - 1, s, v, w);
        return dp[n][s] = max(op1, op2);
    }
    else
    {
        return dp[n][s] = unbound_knapsac(n - 1, s, v, w);
    }
}
int main()
{
    int n;
    cin >> n;
    int v[n], w[n];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        w[i] = i + 1;
    }
    cout << unbound_knapsac(n, n, v, w) << endl;
    return 0;
}