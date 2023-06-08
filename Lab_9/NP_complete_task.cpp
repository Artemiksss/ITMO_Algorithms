#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<vector<int>> graph;
vector<bool> color;

void dfs(int v){
    color[v] = 1;
    for(int i : graph[v]){
        if (!color[i]){
            dfs(i);
        }
    }
}

void initial_actions(int num){
    for(int i = 0; i < num + 1; i++){
        graph.push_back({});
        color.push_back(0);
    }
}

int degrees_of_vertices(int count, int num){
    for(int i = 1;i < num + 1;i ++){
        if(graph[i].size() < 2) {
            count++;
        }
    }
    return count;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    int count_of_bad_vertices = 0;

    cin >> n >> m;
    if (((m > 0) && (m <= pow(10, 5))) && ((n > 0) && (n <= pow(10, 5)))) {
        initial_actions(n);

        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        if (degrees_of_vertices(count_of_bad_vertices, n) > 2) {
            cout << "NO\n";
            return 0;
        }

        dfs(n);

        for (int i = 1; i <= n; i++) {
            if (color[i] != 1) {
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
}