#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> tree;
int quantity = 1;

void Filling_in_the_tree(int cord);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        tree.push_back({0, 0, 0});
        cin >> tree[i][1] >> tree[i][2];
    }
    Filling_in_the_tree(0);
    for(int i = 0; i < num; i++){
        cout << tree[i][0] << ' ';
    }
    return 0;
}

void Filling_in_the_tree(int cord){
    if(tree[cord][1] != 0){
        Filling_in_the_tree(tree[cord][1] - 1);
    }
    tree[cord][0] = quantity;
    quantity++;
    if(tree[cord][2] != 0){
        Filling_in_the_tree(tree[cord][2] - 1);
    }
}

