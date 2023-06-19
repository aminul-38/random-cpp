#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> dp(N, -1);
int fibo(int n)
{
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}
int main()
{
    int n;
    cin >> n;
    dp[1] = 0, dp[2] = 1;
    fibo(n);
    for (int i = 1; i <= n; i++)
        cout << dp[i] << " ";
}