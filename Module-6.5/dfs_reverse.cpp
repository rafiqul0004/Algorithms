#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> adj[N];
vector<int> v;
int visited[N];
void dfs(int u)
{
    visited[u] = true;
    v.push_back(u);
    for (int v : adj[u])
    {
        if (visited[v] == true)
            continue;
        dfs(v);
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
    dfs(1);
    reverse(v.begin(), v.end());
    for (auto i : v)
        cout << i << " ";
    return 0;
}