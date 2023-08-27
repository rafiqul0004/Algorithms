#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 105;
bool visited[N][N];
int level[N][N];
int n, m;
vector<pii> path = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
void initialization()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
            level[i][j] = -1;
        }
    }
}
bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
        return true;
    else
        return false;
}
void bfs(int si, int sj)
{
    queue<pii> q;
    visited[si][sj] = true;
    level[si][sj] = 0;
    q.push({si, sj});
    while (!q.empty())
    {
        pii parent = q.front();
        int pi = parent.first;
        int pj = parent.second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            pii child = path[i];
            int cI = pi + child.first;
            int cJ = pj + child.second;
            if (isValid(cI, cJ) && !visited[cI][cJ])
            {
                visited[cI][cJ] = true;
                q.push({cI, cJ});
                level[cI][cJ] = level[pi][pj] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int ki, kj, qi, qj;
        cin >> ki >> kj >> qi >> qj;
        initialization();
        bfs(ki, kj);
        cout << level[qi][qj] << endl;
    }
    return 0;
}
