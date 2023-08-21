#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<string> g;
int n, m;
int visited[N][N];
bool isvalid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int i, int j)
{
    if (!isvalid(i, j))
        return;
    if (visited[i][j])
        return;
    if (g[i][j] == '#')
        return;
    visited[i][j] = true;
    dfs(i, j - 1);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i + 1, j);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        g.push_back(s);
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '#')
                continue;
            if (visited[i][j])
                continue;
            dfs(i, j);
            c++;
        }
    }
    cout << c << endl;

    return 0;
}