#include <iostream>
#include <vector>
using namespace std;


struct Node {
    int value;
    int new_left;
    int new_right;
    int height;
    Node() : new_left(-1), new_right(-1), height(-1) {}
    Node(int value, int leftId, int rightId) : value(value), new_left(leftId), new_right(rightId), height(-1) {}
};

struct AVLTree {
    vector<Node> tree;
    int root;
    AVLTree() = default;
    AVLTree(int n) : tree(vector<Node>(n)), root(0) {}

    int height(int x) {
        if (x == -1) return 0;
        if (this->tree[x].height != -1) return this->tree[x].height;
        return this->tree[x].height = 1 + max(height(this->tree[x].new_left), height(this->tree[x].new_right));
    }

    int balance(int x) {
        return height(this->tree[x].new_right) - height(this->tree[x].new_left);
    }


    int LeftTurn(int x) {
        int y = this->tree[x].new_right;
        this->tree[x].new_right = this->tree[y].new_left;
        this->tree[y].new_left = x;
        this->tree[x].height = max(height(this->tree[x].new_left), height(this->tree[x].new_right)) + 1;
        this->tree[y].height = max(height(this->tree[y].new_left), height(this->tree[y].new_right)) + 1;

        this->root = y;

        return y;
    }

    int bigLeftTurn(int x) {
        this->tree[x].new_right = RightTurn(this->tree[x].new_right);
        return LeftTurn(x);
    }

    int RightTurn(int x) {
        int y = this->tree[x].new_left;
        this->tree[x].new_left = this->tree[y].new_right;
        this->tree[y].new_right = x;
        this->tree[x].height = max(height(this->tree[x].new_left), height(this->tree[x].new_right)) + 1;
        this->tree[y].height = max(height(this->tree[y].new_left), height(this->tree[y].new_right)) + 1;
        return y;
    }

    void treeTurn() {
        if (balance(this->tree[0].new_right) == -1) {
            bigLeftTurn(0);
        } else {
            LeftTurn(0);
        }
    }


    void print() {
        auto root = &this->tree[this->root];
        cout << root->value << ' ' << rezalt(root->new_left, this->root) << ' ' << rezalt(root->new_right, this->root) << '\n';

        for (int i = 0; i < this->tree.size(); i++) {
            if (i == this->root) continue;
            auto el = &this->tree[i];
            if (i < this->root) {
                cout << el->value << ' ' << rezalt(el->new_left, this->root)
                     << ' ' << rezalt(el->new_right, this->root) << '\n';
            } else {
                cout << el->value << ' ' << rezalt(el->new_left, this->root) << ' ' << el->new_right + 1 << '\n';
            }
        }
    }

    int rezalt(int child, int root) {
        if (child == -1) return 0;
        if (child <= root) return child + 2;
        else return child + 1;
    }
};


int main() {

    int n;
    cin >> n;
    auto *tree = new AVLTree(n);
    int val, l, r;
    for (int i = 0; i<n; i++) {
        cin >> val >> l >> r;
        tree->tree[i] = Node(val, l - 1, r - 1);
    }
    tree->treeTurn();
    cout << n << '\n';
    tree->print();
    return 0;
}