#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];
int component[100001];
bool trap[100001];
bool visited[100001];
int num_components = 0;

void dfs(int u) {
    visited[u] = true;
    component[u] = num_components;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
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

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == '1') {
            trap[i] = true;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            num_components++;
            dfs(i);
        }
    }
    
    cout << num_components << endl;
    for (int i = 1; i <= n; i++) {
        cout << component[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= num_components; i++) {
        bool has_trap = false;
        for (int j = 1; j <= n; j++) {
            if (component[j] == i && trap[j]) {
                has_trap = true;
                break;
            }
        }
        if (has_trap) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }
    cout << endl;

    return 0;
}
