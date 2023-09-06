#include <bits/stdc++.h>
using namespace std;
bool ex = false;
void expression(int n, long long x, int a[], long long sum)
{
    if (n == 0)
    {
        if (sum == x)
            ex = true;
    }
    else
    {
        expression(n - 1, x, a, sum + a[n - 1]);
        expression(n - 1, x, a, sum - a[n - 1]);
    }
}
int main()
{
    int n;
    long long x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    expression(n, x, a, 0);
    if (ex == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}