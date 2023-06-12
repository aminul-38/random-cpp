#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = 1e9;

vector<int> Dijkstra(vector<pair<int, int>> graph[], int source, int node) {
    vector<int> destination(node, INF);
    vector<int> visited(node, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    destination[source] = 0;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int node_no = pq.top().second;
        pq.pop();
        
        if (visited[node_no])
            continue;
        
        visited[node_no] = 1;
        
        for (auto& neighbor : graph[node_no]) {
            int child_node = neighbor.first;
            int child_weight = neighbor.second;
            
            if (destination[node_no] + child_weight < destination[child_node]) {
                destination[child_node] = destination[node_no] + child_weight;
                pq.push({destination[child_node], child_node});
            }
        }
    }
    
    return destination;
}

int main() {
    int node, edge;
    cout << "Enter the number of nodes and edges: ";
    cin >> node >> edge;
    
    vector<pair<int, int>> graph[node + 1];
    
    cout << "Enter the adjacent nodes and weights: ";
    for (int i = 0; i < edge; i++) {
        int node_1, node_2, weight;
        cin >> node_1 >> node_2 >> weight;
        
        graph[node_1].push_back({node_2, weight});
        graph[node_2].push_back({node_1, weight});
    }
    
    cout << "Enter the source and destination nodes: ";
    int source, destination;
    cin >> source >> destination;
    
    vector<int> dest = Dijkstra(graph, source, node + 1);
    
    cout << "Shortest distances from the source node:\n";
    for (int i = 1; i <= node; i++) {
        cout << "Node " << i << ": " << dest[i] << "\n";
    }
    
    cout << "Shortest distance to the destination node: " << dest[destination] << endl;
    
    return 0;
}
