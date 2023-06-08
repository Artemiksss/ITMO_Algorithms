#include <iostream>
using namespace std;

const int MaxSize = 201;
int distances[MaxSize][MaxSize][MaxSize];

struct Coordinates {
    int x, y, z;
};

struct node {
    node *next = nullptr;
    Coordinates val{0, 0, 0};
};

class Queue {
private:
    node *root = nullptr;
    node *end = nullptr;

public:
    void push(Coordinates val) {
        auto *new_node = new node;
        new_node->val = val;

        if(root == nullptr || end == nullptr) {
            root = new_node;
            end = new_node;
        } else {
            end->next = new_node;
            end = new_node;
        }
    }

    Coordinates front() {
        return root->val;
    }

    void pop() {
        if(root == end) {
            end = nullptr;
            delete root;
            root = nullptr;
        } else {
            node *tmp = root->next;

            delete root;
            root = tmp;
        }
    }

    bool empty() {
        return root == nullptr;
    }
};

Coordinates directions[6] = {Coordinates{1, 0, 0}, Coordinates{0, 1, 0}, Coordinates{0, 0, 1},
                             Coordinates{-1, 0, 0},Coordinates{0, -1, 0},Coordinates{0, 0, -1}};

int bfs(const Coordinates start, const Coordinates end) {
    Queue q;
    q.push(start);

    distances[start.x][start.y][start.z] = 0;

    while(!q.empty()) {
        Coordinates v = q.front();
        q.pop();

        for(Coordinates direct : directions) {
            Coordinates new_v = {v.x+direct.x, v.y+direct.y, v.z+direct.z};
            if (((new_v.x < MaxSize) && (new_v.y < MaxSize) && (new_v.z < MaxSize)) && ((new_v.x >= 0) && (new_v.y >= 0) && (new_v.z >= 0)) && distances[new_v.x][new_v.y][new_v.z] != -10) {
                if(distances[new_v.x][new_v.y][new_v.z] == -1) {
                    q.push(new_v);
                    distances[new_v.x][new_v.y][new_v.z] = distances[v.x][v.y][v.z] + 1;
                }
                distances[new_v.x][new_v.y][new_v.z] = min(distances[new_v.x][new_v.y][new_v.z], distances[v.x][v.y][v.z] + 1);
            }
        }
    }

    return distances[end.x][end.y][end.z];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, e;
    int x, y, z;

    for(x = 0; x < MaxSize; x++)
        for(y = 0; y < MaxSize; y++)
            for(z = 0; z < MaxSize; z++)
                distances[x][y][z] = -1;

    cin >> k >> e;

    cin >> x >> y >> z;
    Coordinates start{x, y, z};

    cin >> x >> y >> z;
    Coordinates end{x, y, z};

    for(int i = 0; i < k; i++) {
        int h;
        cin >> x >> y >> z >> h;

        for(int j = z; j < z + h; j++)
            distances[x][y][j] = -10;
    }

    if(((start.x == end.x) && (start.y == end.y) && (start.z == end.z))) {
        cout << 0;
        return 0;
    }

    if(distances[start.x][start.y][start.z] == -10 || distances[end.x][end.y][end.z] == -10) {
        cout << -1;
        return 0;
    }

    int answer = bfs(start, end);
    if(answer > e) {
        cout << -1;
    } else
        cout << answer;

    return 0;
}