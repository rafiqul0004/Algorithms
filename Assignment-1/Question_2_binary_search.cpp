#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ra[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ra[i];
    }
    int x, l, r;
    cin >> x;
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (ra[mid] == x)
        {
            cout << mid << endl;
            return 0;
        }
        if (x > ra[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << "Not Found" << endl;
    return 0;
}