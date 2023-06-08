#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
struct Edge {
    int from, to, weight;
};

vector<Edge> edges;
vector<int> dist;
vector<int> parent;
int n, m;

bool bellman_ford() {
    dist.assign(n, INF);
    dist[0] = 0;
    parent.assign(n, -1);

    for (int i = 0; i < n - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.from] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[edge.from] + edge.weight;
                parent[edge.to] = edge.from;
            }
        }
    }

    for (const auto& edge : edges) {
        if (dist[edge.from] + edge.weight < dist[edge.to]) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int start, end, result;
        cin >> start >> end >> result;
        edges.push_back({start - 1, end - 1, result});
    }

    if (bellman_ford()) {
        cout << 1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
