#include <bits/stdc++.h>
using namespace std;
void Merge(int arr1[], int arr2[], int n, int m)
{
    vector<int> arr;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr.push_back(arr1[i]);
            i++;
        }
        else
        {
            arr.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n)
    {
        arr.push_back(arr1[i]);
        i++;
    }
    while (j < m)
    {
        arr.push_back(arr2[j]);
        j++;
    }
    for (auto v : arr)
        cout << v << " ";
}
int main()
{
    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    Merge(arr1, arr2, n, m);
}