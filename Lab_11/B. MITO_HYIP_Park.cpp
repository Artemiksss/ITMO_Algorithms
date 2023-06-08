#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAXN = 101;
int dist[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INT_MAX;
            }
        }
    }
    int s, e, l;
    for (int i = 0; i < m; ++i) {
        cin >> s >> e >> l;
        dist[s][e] = l;
        dist[e][s] = l;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int max_dist = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (dist[i][j] < INT_MAX && dist[i][j] > max_dist) {
                max_dist = dist[i][j];
            }
        }
    }

    if (max_dist == 0) {
        cout << 0 << endl;
    } else {
        cout << max_dist << endl;
    }

    return 0;
}
