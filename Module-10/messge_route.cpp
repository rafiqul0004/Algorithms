#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> adj[N];
bool visited[N];
vector<int> parent(N, -1);
int level[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    level[s] = 0;
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            parent[v] = u;
            level[v] = level[u] + 1;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    cout << level[n] << endl;
    int current = n;
    vector<int> path;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    for (auto val : path)
    {
        cout << val << " ";
    }
    return 0;
}