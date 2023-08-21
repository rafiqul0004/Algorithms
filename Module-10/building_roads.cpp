#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> adj[N];
bool visited[N];
void dfs(int u)
{
    visited[u] = true;
    for (auto v : adj[u])
    {
        if (visited[v])
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
    vector<long long int> leader;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        leader.push_back(i);
        dfs(i);
    }
    cout << leader.size() - 1 << endl;
    for (long long int i = 1; i < leader.size(); i++)
    {
        cout << leader[i - 1] << " " << leader[i] << endl;
    }

    return 0;
}