#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 5;
bool visited[N][N];
char a[N][N];
vector<pii> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m && a[cI][cJ] == '.')
        return true;
    else
        return false;
}
int bfs(int si, int sj)
{
    int count = 0;
    queue<pii> q;
    visited[si][sj] = true;
    q.push({si, sj});
    count++;
    while (!q.empty())
    {
        pii parent = q.front();
        int pi = parent.first;
        int pj = parent.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pii child = path[i];
            int cI = pi + child.first;
            int cJ = pj + child.second;
            if (isValid(cI, cJ) && !visited[cI][cJ])
            {
                visited[cI][cJ] = true;
                q.push({cI, cJ});
                count++;
            }
        }
    }
    return count;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int area = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.' && !visited[i][j])
                area = min(area, bfs(i, j));
        }
    }
    if (area == INT_MAX)
        cout << -1 << endl;
    else
        cout << area << endl;
    return 0;
}