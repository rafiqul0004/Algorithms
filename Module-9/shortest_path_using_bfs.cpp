#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
bool visited[N];
vector<int> adj[N];
int level[N];
int parent[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    level[s] = 0;
    parent[s] = -1;
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s, d;
    cin >> s >> d;
    bfs(s);
    cout << "Distance " << level[d] << endl;
    vector<int> v;
    int current = d;
    while (current != -1)
    {
        v.push_back(current);
        current = parent[current];
    }
    reverse(v.begin(), v.end());
    cout << "Path : ";
    for (int path : v)
    {
        cout << path << " ";
    }
    return 0;
}