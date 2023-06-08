#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int from, to, weight;
};

int n, m;
void read_Graph(vector<Edge> &edges) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a - 1, b - 1, c});
    }
}

void make_set(vector<int> &parent, vector<int> &color, int v) {
    parent[v] = v;
    color[v] = 0;
}

int find_set(vector<int> &parent, vector<int> &color, int v) {
    if (parent[v] == v) {
        return v;
    }
    return parent[v] = find_set(parent, color,parent[v]);
}

void union_sets(vector<int> &parent, vector<int> &color, int a, int b) {
    a = find_set(parent, color,a);
    b = find_set(parent, color,b);
    if (a != b) {
        if (color[a] < color[b]) {
            swap(a, b);
        }
        parent[b] = a;
        if (color[a] == color[b]) {
            color[a]++;
        }
    }
}

int Kruskal(vector<Edge> &edges, vector<int> &parent, vector<int> &color, int ignore_edge) {
    parent.resize(n);
    color.resize(n);
    for (int i = 0; i < n; i++) {
        make_set(parent, color, i);
    }
    int cost = 0;
    int num_of_edges = 0;
    for (int i = 0; i < m; i++) {
        if (i == ignore_edge) {
            continue;
        }
        int a = edges[i].from, b = edges[i].to, w = edges[i].weight;
        if (find_set(parent, color,a) != find_set(parent, color,b)) {
            cost += w;
            union_sets(parent, color, a, b);
            num_of_edges++;
        }
        if (num_of_edges == n - 1) {
            break;
        }
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<Edge> edges;
    vector<int> parent;
    vector<int> color;
    read_Graph(edges);
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    });

    int min_cost = INT_MAX;
    int second_min_cost = INT_MAX;
    int ignored_edge = -1;

    min_cost = Kruskal(edges, parent, color, -1);

    for (int i = 0; i < m; i++) {
        parent.clear();
        color.clear();
        ignored_edge = i;
        int current_cost = Kruskal(edges, parent, color, ignored_edge);
        if (current_cost < second_min_cost && current_cost > min_cost) {
            second_min_cost = current_cost;
        }
    }

    cout << min_cost << " " << second_min_cost << endl;

    return 0;
}
