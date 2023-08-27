#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visited[N];
vector<int> adj[N];
vector<int> cmp;
void dfs(int src)
{
    visited[src] = true;
    cmp.push_back(src);
    for (auto child : adj[src])
    {
        if (!visited[child])
        {
            dfs(child);
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
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i);
            for (int val : cmp)
            {
                cout << val << " ";
            }
            cout << endl;
            cmp.clear();
        }
    }
    cout << count;
    return 0;
}