#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

vector<vector<Edge>> buildGraph(int n, int m) {
    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    return graph;
}

vector<int> Dijkstra(int start, const vector<vector<Edge>>& graph) {
    int n = graph.size() - 1;
    vector<int> dist(n + 1, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n, m, q, start;
    cin >> n >> m >> q >> start;

    vector<vector<Edge>> graph = buildGraph(n, m);

    vector<int> dist = Dijkstra(start, graph);

    for (int i = 0; i < q; ++i) {
        int dest;
        cin >> dest;
        if (dist[dest] == INF) {
            cout << "-1\n";
        } else {
            cout << dist[dest] << "\n";
        }
    }
    return 0;
}