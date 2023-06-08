#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 5;

vector<int> adj[N];
int vis[N];

bool dfs(int u, int p, int cnt) {
    vis[u] = cnt;
    for (int v : adj[u]) {
        if (v == p){
            continue;
        }
        if (vis[v] == cnt){
            return true;
        }
        if (dfs(v, u, cnt)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            cnt++;
            if (dfs(i, 0, cnt)) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
