#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, ks;
    cin >> n >> m >> ks;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < m; i++) {
        int s, e, l;
        cin >> s >> e >> l;
        dist[s - 1][e - 1] = l;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (abs(k - i) <= ks and abs(k - j) <= ks) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int countt;
    cin >> countt;
    for (int i = 0; i < countt; i++){
        int a, b;
        cin >> a >> b;
        if (dist[a - 1][b - 1] == INF) {
            cout << "-1" << endl;
        } else {
            cout << dist[a - 1][b - 1] << endl;
        }
    }

    return 0;
}