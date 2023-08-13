#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
int visited[N];
int bfs(int s)
{
    int count = 1;
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
            count++;
            q.push(v);
            visited[v] = true;
        }
    }
    return count;
}
int main()
{
    vector<int> v;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i <= 1000; i++)
    {
        if (visited[i])
            continue;
        int f = bfs(i);
        if (f > 1)
            v.push_back(f);
    }
    sort(v.begin(), v.end());
    for (int val : v)
    {
        cout << val << " ";
    }
    return 0;
}