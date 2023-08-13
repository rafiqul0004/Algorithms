#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
vector<int> adj[N];
bool visited[N];
int bfs(int s)
{
    int c = 0;
    queue<int> q;
    q.push(s);
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
            c++;
        }
    }
    return c;
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
    }
    int t;
    cin >> t;
    int f = bfs(t);
    cout << f << endl;
    return 0;
}