#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visited[N];
vector<int> adj[N];
void dfs(int src)
{
    visited[src] = true;
    cout << src << endl;
    // for (int i = 0; i < adj[src].size(); i++)
    // {
    //     int child = adj[src][i];
    //     if (visited[child] == true)
    //         continue;
    //     dfs(child);
    // }
    for (auto v : adj[src])
    {
        if (visited[v] == true)
            continue;
        dfs(v);
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
    dfs(1);
    return 0;
}