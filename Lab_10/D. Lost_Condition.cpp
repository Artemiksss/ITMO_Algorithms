#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> new_names(n);
    int cur_name = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        new_names[u] = cur_name;
        cur_name++;

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << new_names[i] << " ";
    }
    cout << endl;

    return 0;
}
