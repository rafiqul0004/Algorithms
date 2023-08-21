#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int m, int r)
{
    int leftsize = m - l + 1;
    int rightsize = r - m;
    int L[leftsize];
    int R[rightsize];
    int k = 0;
    for (int i = l; i <= m; i++)
    {
        L[k] = a[i];
        k++;
    }
    k = 0;
    for (int i = m + 1; i <= r; i++)
    {
        R[k] = a[i];
        k++;
    }
    int i = 0, j = 0;
    int b = l;
    while (i < leftsize && j < rightsize)
    {
        if (L[i] <= R[j])
        {
            a[b] = L[i];
            i++;
        }
        else
        {
            a[b] = R[j];
            j++;
        }
        b++;
    }
    while (i < leftsize)
    {
        a[b] = L[i];
        i++;
        b++;
    }
    while (j < rightsize)
    {
        a[b] = R[j];
        j++;
        b++;
    }
}
void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}