#include <vector>
#include <iostream>
using namespace std;

int *result;
int quantity;
vector<vector<int>> tree;
void checking(int node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    quantity = 0;
    int num;
    cin >> num;
    if(num == 0){
        cout << "YES\n";
        return 0;
    }
    int t[num];
    result = &t[0];
    for(int i = 0; i < num; i++){
        tree.push_back({0,0,0});
        cin >> tree[i][0] >> tree[i][1]>> tree[i][2];
    }
    checking(0);
    for(int i = 0; i < num - 1; i++){
        if(result[i] >= result[i + 1]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}

void checking(int node){
    if(tree[node][1] > 0){
        checking(tree[node][1] - 1);
    }
    result[quantity] = tree[node][0];
    quantity++;
    if(tree[node][2] > 0){
        checking(tree[node][2] - 1);
    }
}
