#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a, b;
    Edge(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
};
const int N = 1e5 + 5;
int parent[N];
int parentSize[N];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int main()
{
    int n, e;
    cin >> n;
    e = n - 1;
    dsu_set(n);
    vector<pair<int, int>> v1;
    vector<Edge> v;
    vector<pair<int, int>> v2;
    vector<Edge> ans;
    dsu_set(n);
    while (e--)
    {
        int a, b, w;
        cin >> a >> b;
        v.push_back(Edge(a, b));
    }
    for (Edge val : v)
    {
        int a = val.a;
        int b = val.b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
        {
            v1.push_back({a, b});
        }
        else
        {

            dsu_union(a, b);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (dsu_find(i) == dsu_find(j))
                continue;
            v2.push_back({i, j});
            dsu_union(i, j);
        }
    }

    cout << v2.size() << endl;
    if (v2.size() != 0)
    {
        for (int i = 0; i < v2.size(); i++)
        {
            cout << v1[i].first << " " << v1[i].second << " " << v2[i].first << " " << v2[i].second << endl;
        }
    }
    return 0;
}