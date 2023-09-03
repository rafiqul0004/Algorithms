#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a, b;
    long long w;
    Edge(int a, int b, long long w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }
    long long dist[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = LLONG_MAX;
    }
    int src;
    cin >> src;
    dist[src] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            int a = ed.a;
            int b = ed.b;
            long long w = ed.w;
            if (dist[a] + w < dist[b] && dist[a] != LLONG_MAX)
            {
                dist[b] = dist[a] + w;
            }
        }
    }
    bool cycle = false;
    for (int j = 0; j < v.size(); j++)
    {
        Edge ed = v[j];
        int a = ed.a;
        int b = ed.b;
        long long w = ed.w;
        if (dist[a] + w < dist[b] && dist[a] != LLONG_MAX)
        {
            cycle = true;
            break;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        if (cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
        else if (dist[d] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else
            cout << dist[d] << endl;
    }

    return 0;
}