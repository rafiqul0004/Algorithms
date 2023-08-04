#include <bits/stdc++.h>
using namespace std;
void marge(int ra1[], int ra2[], int n, int m, int nums[])
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (ra1[i] > ra2[j])
        {
            nums[k++] = ra1[i++];
        }
        else
            nums[k++] = ra2[j++];
    }
    while (i < n)
    {
        nums[k++] = ra1[i++];
    }
    while (j < m)
    {
        nums[k++] = ra2[j++];
    }
}
int main()
{
    int n;
    cin >> n;
    int ra1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ra1[i];
    }
    int m;
    cin >> m;
    int ra2[m];
    for (int i = 0; i < m; i++)
    {
        cin >> ra2[i];
    }
    int nums[n + m];
    marge(ra1, ra2, n, m, nums);
    for (int i = 0; i < n + m; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}