#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 5;
const int INF = INT_MAX;
vector<pii> g[N];
long long int d[N];
long long int n, e;
void bellman(int s)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    d[s] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (pii vpair : g[u])
            {
                int v = vpair.first;
                int w = vpair.second;
                if (d[u] != INF && d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                }
            }
        }
    }
}
int main()
{
    cin >> n >> e;
    while (e--)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    int s, t;
    cin >> s;
    bellman(s);
    cin >> t;
    while (t--)
    {
        long long int a, b;
        cin >> a >> b;
        if (d[a] <= b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}