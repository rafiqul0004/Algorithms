#include <bits/stdc++.h>
using namespace std;
int knapsac(int n, int s, int w[], int v[])
{
    if (n == 0 || s == 0)
        return 0;
    if (w[n - 1] <= s)
    {
        int op1 = knapsac(n - 1, s - w[n - 1], w, v) + v[n - 1];
        int op2 = knapsac(n - 1, s, w, v);
        return max(op1, op2);
    }
    else
    {
        return knapsac(n - 1, s, w, v);
    }
}
int main()
{
    int n, s;
    cin >> n >> s;
    int w[n], v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << knapsac(n, s, w, v) << endl;
    return 0;
}