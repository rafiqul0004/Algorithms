#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
vector<int> v;
void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v] == true)
            continue;
        dfs(v);
    }
}
void reinitialize()
{
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }
}
void dfs2(int r)
{
    visited[r] = true;
    cout << r << " ";
    for (int d : adj[r])
    {
        if (visited[d] == true)
            continue;
        dfs(d);
    }
    cout << endl;
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
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        v.push_back(i);
        count++;
    }
    cout << count << endl;
    reinitialize();
    for (int i = 0; i < v.size(); i++)
    {
        cout << "Components : ";
        dfs2(v[i]);
    }

    return 0;
}