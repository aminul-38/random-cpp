#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<int> Dijkstra(vector<pair<int, int>> (&graph)[], int source, int node)
{
    vector<int> destination(node, INF);
    vector<int> visited(node, 0);
    set<pair<int, int>> st;
    destination[source] = 0;
    st.insert({0, source});
    while (!st.empty())
    {
        auto node = *st.begin();
        int node_weight = node.first;
        int node_no = node.second;
        st.erase(st.begin());
        if (visited[node_no])
            continue;
        visited[node_no] = 1;
        for (int i = 0; i < graph[node_no].size(); i++)
        {
            int child_node = graph[node_no][i].first;
            int child_wight = graph[node_no][i].second;
            if (destination[node_no] + child_wight < destination[child_node])
            {
                destination[child_node] = destination[node_no] + child_wight;
                st.insert({destination[child_node], child_node});
            }
        }
    }
    return destination;
}
int main()
{
    int node, edge;
    cout << "Enter number of node and edge : ";
    cin >> node >> edge;
    vector<pair<int, int>> graph[node + 1];
    cout << "Enter adjacent node and weight : ";
    for (int i = 0; i < edge; i++)
    {
        int node_1, node_2, weight;
        cin >> node_1 >> node_2 >> weight;
        graph[node_1].push_back(make_pair(node_2, weight));
        graph[node_2].push_back({node_1, weight});
    }
    cout << "Enter source and destination node : ";
    int source, destination;
    cin >> source >> destination;
    vector<int> dest = Dijkstra(graph, source, node + 1);
    for (auto it = dest.begin(); it != dest.end(); it++)
        cout << *it << " ";
    cout << endl;
    cout << dest[destination] << endl;
}
