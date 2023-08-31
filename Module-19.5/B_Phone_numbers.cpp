#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char s[1000];
    while (n--)
    {
        cin >> s;
    }
    int l = strlen(s);
    cout << s[0];
    if (l % 2 == 0)
    {
        for (int i = 1; i < l; i++)
        {
            if ((i % 2 == 0) && (i <= l - 2))
                cout << "-";
            cout << s[i];
        }
    }
    else
    {
        for (int i = 1; i < l; i++)
        {
            if ((i % 2 == 0) && (i <= l - 3))
                cout << "-";
            cout << s[i];
        }
    }
    return 0;
}