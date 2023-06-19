#include <bits/stdc++.h>
using namespace std;
int max_sub_arr(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    int mid = n / 2;
    int left_sub_arr = max_sub_arr(arr, mid);
    int right_sub_arr = max_sub_arr(arr + mid, n - mid);
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum{};
    for (int i = mid - 1; i >= 0; i--)
    {
        sum += arr[i];
        left_sum = max(sum, left_sum);
    }
    sum = 0;
    for (int i = mid; i < n; i++)
    {
        sum += arr[i];
        right_sum = max(sum, right_sum);
    }
    int ans = max(left_sub_arr, right_sub_arr);
    return max(ans, right_sum + left_sum);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << max_sub_arr(arr, n) << endl;
}