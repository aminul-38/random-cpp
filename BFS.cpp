#include <bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>> &graph, int source)
{
    int node = graph.size();
    queue<int> q;
    vector<bool> visited(node, false);
    q.push(source);
    visited[source] = true;
    vector<int> level(node, 0);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        for (auto adjacent : graph[temp])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                q.push(adjacent);
                level[adjacent] = level[temp] + 1;
            }
        }
    }
    /* cout << endl;
    int max{};
    for (int i = 1; i < node; i++)
    {
        if (level[i] > max)
            max = level[i];
    }
    cout << max << endl; */
}
int main()
{
    int node, edge;
    cout << "Enter number of node and edge : ";
    cin >> node >> edge;
    cout << "Enter adjacent nodes : ";
    vector<vector<int>> graph(node + 1);
    for (int i = 0; i < edge; i++)
    {
        int node_1, node_2;
        cin >> node_1 >> node_2;
        graph[node_1].push_back(node_2);
        graph[node_2].push_back(node_1);
    }
    int source;
    cout << "Enter source node : ";
    cin >> source;
    BFS(graph, source);
}