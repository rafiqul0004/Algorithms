#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int nums[N];
void merge(int l, int r, int mid)
{
    int l_size = mid - l + 1;
    int arr1[l_size + 1];
    int r_size = r - mid;
    int arr2[r_size + 1];
    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        arr1[j] = nums[i];
    }
    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        arr2[j] = nums[i];
    }
    arr1[l_size] = INT_MIN;
    arr2[r_size] = INT_MIN;
    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (arr1[lp] >= arr2[rp])
        {
            nums[i] = arr1[lp];
            lp++;
        }
        else
        {
            nums[i] = arr2[rp];
            rp++;
        }
    }
}
void mergesort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, r, mid);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    mergesort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}