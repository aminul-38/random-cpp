#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int value[N], weight[N];
int DP[N][N];
int KnapSack(int element, int nk_weight_left)
{
    if (element < 0)
        return 0;
    if (nk_weight_left <= 0)
        return 0;
    if (DP[element][nk_weight_left] != -1)
        return DP[element][nk_weight_left];
    int max_sum = KnapSack(element - 1, nk_weight_left); // if we don't choose the element
    if (weight[element] <= nk_weight_left)
    {
        // if we choose the element
        max_sum = max(max_sum, KnapSack(element - 1, nk_weight_left - weight[element]) + value[element]);
    }
    return DP[element][nk_weight_left] = max_sum;
}
int main()
{
    memset(DP, -1, sizeof(DP));
    int element_num, nk_weight;
    cout << "Enter number of element and max weight : ";
    cin >> element_num >> nk_weight;
    cout << "Enter weight and value of each element : " << endl;
    for (int i = 0; i < element_num; i++)
    {
        cin >> weight[i] >> value[i];
    }
    cout << "Maximum weight  : " << KnapSack(element_num - 1, nk_weight);
}