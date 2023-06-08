#include <iostream>
#include <vector>
#include <queue>

using namespace std;


bool bfs(vector<vector<int>>& graph, int start, int end) {
    queue<int> q;
    vector<bool> visited(graph.size(), false);

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (neighbor == end) {
                return true;
            }
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        if (bfs(graph, a, b)) {
            if (bfs(graph, b, a)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
