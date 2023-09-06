#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int r, c;
int m[N][N];
int m_path(int i, int j)
{
    int sum = INT_MIN;
    if (i == r && j == c)
        return m[i][j];
    if (i < r)
        sum = max(sum, m[i][j] + m_path(i + 1, j));
    if (j < c)
        sum = max(sum, m[i][j] + m_path(i, j + 1));
    return sum;
}
int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> m[i][j];
        }
    }
    cout << m_path(1, 1);
    return 0;
}