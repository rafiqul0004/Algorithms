#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<int> adj[N];
bool visited[N];
int level[N];
void bfs(int s)
{
    queue<int> qu;
    qu.push(s);
    visited[s] = true;
    level[s] = 0;
    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for (int v : adj[u])
        {
            if (visited[v] == true)
                continue;
            qu.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
}
void initialization()
{
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        level[i] = -1;
    }
}
int main()
{
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        initialization();
        bfs(a);
        cout << level[b] << endl;
    }
    return 0;
}