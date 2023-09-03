#include <bits/stdc++.h>
using namespace std;
const long long int INF = LLONG_MAX;
int main()
{
    long long int n, e;
    cin >> n >> e;
    long long int dist[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
            if (i == j)
                dist[i][j] = 0;
        }
    }
    while (e--)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF)
            cout << -1 << endl;
        else
            cout << dist[a][b] << endl;
    }

    return 0;
}