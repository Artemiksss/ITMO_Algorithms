#include <iostream>
#include <vector>

using namespace std;

int n, m, q;
vector<vector<int>> matrix;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : matrix[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int main() {
    cin >> n >> m >> q;
    matrix.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    for (int i = 0; i < q; i++) {
        char znak;
        int a, b;
        cin >> znak >> a >> b;
        if (znak == '?') {
            visited.assign(n + 1, false);
            dfs(a);
            if (visited[b]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else if (znak == '-') {
            for (int j = 0; j < matrix[a].size(); j++) {
                if (matrix[a][j] == b) {
                    matrix[a].erase(matrix[a].begin() + j);
                    break;
                }
            }
            for (int j = 0; j < matrix[b].size(); j++) {
                if (matrix[b][j] == a) {
                    matrix[b].erase(matrix[b].begin() + j);
                    break;
                }
            }
        }
    }
    return 0;
}

