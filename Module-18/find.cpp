#include <bits/stdc++.h>
using namespace std;
int parent[8] = {-1, -1, 1, 1, 6, 4, -1, -1};
int find(int s)
{
    while (parent[s] != -1)
    {
        s = parent[s];
    }
    return s;
}
int main()
{
    cout << find(2);
    return 0;
}