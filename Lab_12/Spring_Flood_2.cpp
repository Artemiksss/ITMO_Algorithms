#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long MAXN = 10000000;

long long parent[MAXN];

struct Edge {
    long long u, v, w;
};

bool operator<(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

int find_parent(long long u) {
    if (parent[u] == u) {
        return u;
    }
    return parent[u] = find_parent(parent[u]);
}

void union_sets(long long u, long long v) {
    u = find_parent(u);
    v = find_parent(v);
    if (u != v) {
        parent[u] = v;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (long long i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--;
    }

    sort(edges.begin(), edges.end());

    for (long long i = 0; i < n; i++) {
        parent[i] = i;
    }

    long long mst_weight = 0;
    for (long long i = 0; i < m; i++) {
        long long u = edges[i].u;
        long long v = edges[i].v;
        long long w = edges[i].w;
        if (find_parent(u) != find_parent(v)) {
            union_sets(u, v);
            mst_weight += w;
        }
    }

    cout << mst_weight << endl;

    return 0;
}
