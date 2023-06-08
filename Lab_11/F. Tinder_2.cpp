#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> graph_DSU, parent_s;

void make_set(int x) {
    if (graph_DSU[x] == -1) {
        graph_DSU[x] = x;
        parent_s[x] = 1;
    }
}

int find_set(int x) {
    if (graph_DSU[x] != x) {
        graph_DSU[x] = find_set(graph_DSU[x]);
    }
    return graph_DSU[x];
}

void union_set(int x, int y) {
    int find_x = find_set(x);
    int find_y = find_set(y);
    if (find_x == find_y) {
        return;
    }
    if (find_x > find_y) {
        graph_DSU[find_y] = find_x;
        parent_s[find_x] = parent_s[find_x] + parent_s[find_y];
    } else {
        graph_DSU[find_x] = find_y;
        parent_s[find_y] = parent_s[find_y] + parent_s[find_x];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<set<int>> graph(n);
    graph_DSU = vector<int>(n, -1);
    parent_s = vector<int>(n, 0);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x - 1].insert(y - 1);
        graph[y - 1].insert(x - 1);
    }
    char znak;
    vector<char> znaki;

    vector<pair<int, int>> pair_erase_DSU;
    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> znak >> a >> b;
        znaki.push_back(znak);
        pair_erase_DSU.emplace_back(make_pair(a - 1, b - 1));
        if (znak == '-') {
            graph[a - 1].erase(b - 1);
            graph[b - 1].erase(a - 1);
        }
    }
    for (int i = 0; i < graph.size(); i++) {
        make_set(i);
    }
    for (int i = 0; i < graph.size(); i++) {
        for (int j: graph[i]) {
            union_set(i, j);
        }
    }
    vector<string> result;
    for (int k = q - 1; k >= 0; k--) {
        if (znaki[k] == '?') {
            if (find_set(pair_erase_DSU[k].first) == find_set(pair_erase_DSU[k].second)) {
                result.emplace_back("YES");
            } else {
                result.emplace_back("NO");
            }
        } else if (znaki[k] == '-') {
            union_set(pair_erase_DSU[k].first, pair_erase_DSU[k].second);
        }
    }
    reverse(result.begin(), result.end());
    for (auto &t: result) {
        cout << t << "\n";
    }

    return 0;
}
