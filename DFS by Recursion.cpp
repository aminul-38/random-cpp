// DFS with recursion
#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> &graph, vector<bool> &visited, int node)
{
    visited[node] = true;
    cout << node << " ";
    for (auto adjacent : graph[node])
    {
        if (!visited[adjacent])
        {
            DFS(graph, visited, adjacent);
        }
    }
}
void DFS_travarsal(vector<vector<int>> &graph, int source)
{
    int nodes = graph.size();
    vector<bool> visited(nodes, false);
    DFS(graph, visited, source);
}
int main()
{
    int node, edge;
    cout << "Enter number of node and edge : ";
    cin >> node >> edge;
    vector<vector<int>> graph(node + 1);
    cout << "Enter adjacent nodes : " << endl;
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
    DFS_travarsal(graph, source);
}