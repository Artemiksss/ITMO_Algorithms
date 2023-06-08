#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int bfs(int s, int t, vector<int>& parent, vector<vector<int>>& flow_size, vector<vector<int>>& graph) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int next : graph[cur]) {
            if (parent[next] == -1 && flow_size[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, flow_size[cur][next]);
                if (next == t) {
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int Max_flow(int s, int n, vector<vector<int>>& flow_size, vector<vector<int>>& graph) {
    int flow = 0;
    int t = n;
    vector<int> parent(n + 1);
    int new_flow;
    new_flow = bfs(s, t, parent, flow_size, graph);
    while (new_flow) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            flow_size[prev][cur] -= new_flow;
            flow_size[cur][prev] += new_flow;
            cur = prev;
        }
        new_flow = bfs(s, t, parent, flow_size, graph);
    }
    return flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    vector<vector<int>> graph;
    vector<vector<int>> flow_size;
    cin >> n >> m;
    graph.resize(n + 1);
    flow_size.resize(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int start, end, bandwidth;
        cin >> start >> end >> bandwidth;
        graph[start].push_back(end);
        graph[end].push_back(start);
        flow_size[start][end] += bandwidth;
    }
    cout << Max_flow(1, n, flow_size, graph) << endl;
    return 0;
}
