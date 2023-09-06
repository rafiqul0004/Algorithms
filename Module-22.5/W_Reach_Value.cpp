#include <bits/stdc++.h>
using namespace std;
bool reach(long long c, long long n)
{
    if (c > n)
        return false;
    if (c == n)
        return true;
    bool op1 = reach(c * 10, n);
    bool op2 = reach(c * 20, n);
    return op1 || op2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (reach(1, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}