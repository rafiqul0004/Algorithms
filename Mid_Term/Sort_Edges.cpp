#include <bits/stdc++.h>
using namespace std;
int main()
{
    int e;
    cin >> e;
    vector<pair<int, int>> a;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        a.push_back({u, v});
    }
    sort(a.begin(), a.end());
    for (auto v : a)
    {
        cout << v.first << " " << v.second << endl;
    }
    return 0;
}