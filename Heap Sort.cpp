#include <bits/stdc++.h>
using namespace std;
void Max_Heap(vector<int> &tree, int n, int parent)
{
    int temp_parent = parent;
    int left_child = 2 * parent + 1;
    int right_child = 2 * parent + 2;

    if (left_child < n && tree[left_child] > tree[temp_parent])
        temp_parent = left_child;
    if (right_child < n && tree[right_child] > tree[temp_parent])
        temp_parent = right_child;

    if (temp_parent != parent)
    {
        swap(tree[temp_parent], tree[parent]);
        Max_Heap(tree, n, temp_parent);
    }
}
void Heap_sort(vector<int> &tree)
{
    int n = tree.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        Max_Heap(tree, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(tree[i], tree[0]);
        Max_Heap(tree, i, 0);
    }
}
int main()
{
    int n;
    cout << "Enter number of element : ";
    cin >> n;
    vector<int> tree(n);
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
        cin >> tree[i];
    Heap_sort(tree);

    cout << "Sorted elements : ";
    for (auto element : tree)
        cout << element << " ";
}