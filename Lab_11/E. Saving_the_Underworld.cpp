#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int dijkstra(const vector<vector<pair<int, int>>>& adj, int s, int t) {
    int n = adj.size();
    vector<int> dist(n, INF);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == t) {
            return dist[t];
        }

        for (auto& [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    return -1;
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s, --t;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        adj[a].emplace_back(b, w);
    }

    int shortest_path = dijkstra(adj, s, t);
    cout << shortest_path << endl;

    return 0;
}
