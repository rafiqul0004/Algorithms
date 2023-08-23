#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 5;
vector<pii> adj[N];
int dist[N];
void dijkstra(int src)
{
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int i = 0; i < adj[parent].size(); i++)
        {
            pii child = adj[parent][i];
            int childNode = child.first;
            int childCost = child.second;
            if (dist[parent] + childCost < dist[childNode])
            {
                dist[childNode] = dist[parent] + childCost;
                q.push(childNode);
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }

    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Distance " << i << " : " << dist[i] << endl;
    }

    return 0;
}