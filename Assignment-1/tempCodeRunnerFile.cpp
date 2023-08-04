void merge(int ra1[], int ra2[], int n, int m)
// {
//     int sz1 = n;
//     int sz2 = m;
//     int i = 0, j = 0, k = 0;
//     while (i < sz1 && j < sz2)
//     {
//         if (ra1[i] > ra2[j])
//         {
//             nums[k] = ra1[i];
//             i++;
//         }
//         else
//         {
//             nums[k] = ra2[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < sz1)
//     {
//         nums[k] = ra1[i];
//         i++;
//         k++;
//     }
//     while (j < sz2)
//     {
//         nums[k] = ra1[j];
//         j++;
//         k++;
//     }
// }