#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visited[N];
int dist[N];
vector<int> adj[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto v : adj[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            dist[v] = dist[u] + 1;
            visited[v] = true;
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Level " << i << " : " << dist[i] << endl;
    }
    return 0;
}