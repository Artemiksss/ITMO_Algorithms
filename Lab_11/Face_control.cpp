#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct Edge {
    int from, to, weight;
};

const int INF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int num_nodes, num_edges;
        cin >> num_nodes >> num_edges;

        vector<Edge> edges(num_edges);
        for (int j = 0; j < num_edges; j++) {
            cin >> edges[j].from >> edges[j].to >> edges[j].weight;
        }

        vector<int> dist(num_nodes + 1, INF);
        dist[1] = 0;
        queue<int> q;
        vector<int> cnt(num_nodes + 1, 0);
        vector<bool> in_queue(num_nodes + 1, false);

        q.push(1);
        cnt[1]++;
        in_queue[1] = true;
        bool has_negative_cycle = false;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = false;
            if (cnt[u] > num_nodes) {
                has_negative_cycle = true;
                break;
            }
            for (int j = 0; j < num_edges; j++) {
                int v = edges[j].to;
                int w = edges[j].weight;
                if (edges[j].from == u && dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    if (!in_queue[v]) {
                        q.push(v);
                        in_queue[v] = true;
                        cnt[v]++;
                    }
                }
            }
        }

        if (has_negative_cycle) {
            cout << "NO" << endl;
        } else {
            bool has_large_cycle = false;
            for (int j = 0; j < num_edges; j++) {
                int u = edges[j].from;
                int v = edges[j].to;
                int w = edges[j].weight;
                if (dist[u] != INF && dist[u] + w < dist[v] && (dist[u] + w - dist[v]) < -k) {
                    has_large_cycle = true;
                    break;
                }
            }
            if (has_large_cycle) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}
