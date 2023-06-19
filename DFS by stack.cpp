// DFS by Stack
#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> &graph, int source)
{
    int ndoe_num = graph.size();
    vector<bool> visited(ndoe_num, false);
    stack<int> st;
    st.push(source);
    visited[source] = true;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        cout << node << " ";
        for (auto adjacent : graph[node])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                st.push(adjacent);
            }
        }
    }
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
    DFS(graph, source);
}