#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int adjm[1000][1000];
vector<int> adj[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> adjm[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adjm[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << " : ";
        for (auto val : adj[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}