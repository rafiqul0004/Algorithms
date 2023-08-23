#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 5;
bool visited[N];
vector<pii> adj[N];
int dist[N];
void dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({dist[src], src}); // source ke push kora
    while (!pq.empty())
    {
        int parent = pq.top().second; // parent ke ber kora
        pq.pop();                     // parent ke pop kora
        visited[parent] = true;       // parent ke true kora
        for (pii child : adj[parent]) // oi parent er child gulo ber kora
        {
            int childNode = child.first;  // childNode
            int childCost = child.second; // childNode er cost
            if (visited[childNode])       // childNode jodi er age eshe thake tahole bad
                continue;
            if (dist[childNode] > dist[parent] + childCost) // childNode er distance jodi parent er distance ebong child er cost theke beshi hoi tahole change
            {
                dist[childNode] = dist[parent] + childCost;
                pq.push({dist[childNode], childNode});
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