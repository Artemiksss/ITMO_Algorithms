#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct Node {
    int data;
    int left;
    int right;

    Node() = default;

    Node(int data, int left, int right) : data(data), left(left), right(right) {}
};


class node{
public:
    node* parent;
    node* leftId;
    node* rightId;
    int value;
    int height;

    node(node* par = nullptr, int v = 0, int h = 1, node* l = nullptr, node* r = nullptr):
            parent(par), leftId(l), rightId(r), value(v), height(h)
    {}
};
int height(node* x);
int balance(node* x);
int Tree_height(node* x);
void fixheight(node* x);
node* LeftTurn(node* x);
node* RightTurn(node* x);
node* rebalance(node* x);
node* findmax(node* x);
node* removemax(node* x);
node* removeNode(node* x, int k);
node* find(node* root, int data);

node* add(node* root, int k, node* der = nullptr){
    if (root == nullptr) return new node(der, k);
    if (k < root -> value) root -> leftId = add(root -> leftId, k, root);
    else root -> rightId = add(root -> rightId, k, root);
    return rebalance(root);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num; cin >> num;
    node* root = nullptr;
    char symbol;
    int i = 0;
    while (i < num){
        cin >> symbol;
        int x; cin >> x;
        if (symbol == 'A'){
            if (find(root, x) == nullptr) root = add(root, x);
            cout << balance(root) << "\n";
        }
        if (symbol == 'D'){
            if (find(root, x) != nullptr) root = removeNode(root, x);
            cout << balance(root) << "\n";
        }
        if (symbol == 'C'){
            if (find(root, x) == nullptr) cout << "N" << "\n";
            else cout << "Y" << "\n";
        }
        i ++;
    }
}
int height(node* x) {
    if (x == nullptr) return 0;
    return x -> height;
}

int balance(node* x) {
    if (x == nullptr) return 0;
    return height(x->rightId) - height(x->leftId);
}

int Tree_height(node* x){
    if (x == nullptr) return 0;
    x->height = max(Tree_height(x->leftId), Tree_height(x->rightId)) + 1;
    return x -> height;
}

void fixheight(node* x){
    x->height = max(height(x->leftId), height(x->rightId)) + 1;
}


node* LeftTurn(node* x) {
    node* y = x->rightId;
    x->rightId = y->leftId;
    y->leftId = x;
    fixheight(x);
    fixheight(y);
    return y;
}


node* RightTurn(node* x) {
    node* y = x->leftId;
    x->leftId = y->rightId;
    y->rightId = x;
    fixheight(x);
    fixheight(y);
    return y;
}
node* rebalance(node* x){
    if (x==nullptr) return nullptr;
    fixheight(x);
    if(balance(x)==2)
    {
        if (balance(x->rightId) < 0)
            x->rightId = RightTurn(x->rightId);
        return LeftTurn(x);
    }
    if(balance(x)== -2){
        if (balance(x->leftId) > 0)
            x->leftId = LeftTurn(x->leftId);
        return RightTurn(x);
    }
    fixheight(x);
    return x;
}

node* findmax(node* x){
    if (x->rightId==nullptr) return x;
    return findmax(x->rightId);
}

node* removemax(node* x){
    if (x->rightId == nullptr)
        return x->leftId;
    x->rightId = removemax(x->rightId);
    return rebalance(x);
}

node* removeNode(node* x, int k){
    if (!x) return nullptr;
    if (x -> value == k && x -> leftId == nullptr && x -> rightId == nullptr){
        delete x;
        return nullptr;
    }
    if (k < x->value)
        x->leftId = removeNode(x->leftId, k);
    else if (k > x->value)
        x->rightId = removeNode(x->rightId, k);
    else {
        node *lchild = x->leftId;
        node *rchild = x->rightId;
        delete (x);
        if (lchild == nullptr) return rchild;
        if (rchild == nullptr) return lchild;
        node* maxNode = findmax(lchild);
        maxNode->leftId = removemax(lchild);
        maxNode->rightId = rchild;
        return rebalance(maxNode);
    }
    return rebalance(x);
}
node* find(node* root, int data){
    if (root == nullptr) return nullptr;
    if (root -> value == data) return root;
    if (data < root -> value) return find(root -> leftId, data);
    else return find(root -> rightId, data);
}
