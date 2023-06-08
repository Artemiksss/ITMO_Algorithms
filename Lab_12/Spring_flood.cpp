#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1000000;

int parent[MAXN];

struct Edge {
    int u, v, w;
};

bool operator<(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

int find_parent(int u) {
    if (parent[u] == u) {
        return u;
    }
    return parent[u] = find_parent(parent[u]);
}

void union_sets(int u, int v) {
    u = find_parent(u);
    v = find_parent(v);
    if (u != v) {
        parent[u] = v;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--;
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int mst_weight = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (find_parent(u) != find_parent(v)) {
            union_sets(u, v);
            mst_weight += w;
        }
    }

    cout << mst_weight << endl;

    return 0;
}
