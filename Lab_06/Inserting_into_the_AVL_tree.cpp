#include <iostream>
#include <vector>
using namespace std;


struct Node {
    int data;
    int left;
    int right;

    Node() = default;
    Node(int data, int left, int right) : data(data), left(), right(right) {}
};


struct AVLTree {
    struct node {
        int value;
        node *left_new;
        node *right_new;
        int height;
        node(): value(-1), left_new(nullptr), right_new(nullptr), height(-1) {}
    };
    AVLTree(): root(nullptr){}
    node *root;


    int height(node* x) {
        if (x == nullptr) return -1;
        if (x->height == -1) fixheight(x);
        return x->height;
    }

    int balance(node* x) {
        return height(x->right_new) - height(x->left_new);
    }

    void fixheight(node* x){
        x->height = max(height(x->left_new), height(x->right_new)) + 1;
    }


    node* LeftTurn(node* x) {
        node* y = x->right_new;
        x->right_new = y->left_new;
        y->left_new = x;
        fixheight(x);
        fixheight(y);
        return y;
    }


    node* RightTurn(node* x) {
        node* y = x->left_new;
        x->left_new = y->right_new;
        y->right_new = x;
        fixheight(x);
        fixheight(y);
        return y;
    }

    node* rebalance(node* x){
        fixheight(x);
        if(balance(x)==2)
        {
            if (balance(x->right_new) < 0)
                x->right_new = RightTurn(x->right_new);
            return LeftTurn(x);
        }
        if(balance(x)== -2){
            if (balance(x->left_new) > 0)
                x->left_new = LeftTurn(x->left_new);
            return RightTurn(x);
        }
        fixheight(x);
        return x;
    }



    void  add(int x){
        root = insert(root, x);
    }

    node* insert(node* root, int x){
        if (root == nullptr ) {
            root = new node;
            root->value = x;
            root->height = 0;
            root->left_new=nullptr;
            root->right_new=nullptr;
            return root;
        }
        if (x < root->value)
            root->left_new = insert(root->left_new,x);
        else
            root->right_new = insert(root->right_new,x);
        return rebalance(root);
    }

    vector<Node> Rezult_Tree;

    void Rezalt(int &root, node *x){
        if (x == nullptr) return;
        int curTemp = root;
        Rezult_Tree[root-1].data = x->value;
        if (x->left_new == nullptr) Rezult_Tree[root-1].left = 0;
        else {
            Rezult_Tree[root - 1].left = root + 1;
            root++;
            Rezalt(root, x->left_new);
        }

        if (x->right_new == nullptr) Rezult_Tree[curTemp - 1].right = 0;
        else {
            Rezult_Tree[curTemp - 1].right = root + 1;
            root++;
            Rezalt(root, x->right_new);
        }
    }

    void print(int n) {
        Rezult_Tree.resize(n);
        int i = 1;
        Rezalt(i, root);

        for (auto x: Rezult_Tree) {
            cout << x.data << ' ' << x.left << ' ' << x.right << '\n';
        }
    }



};



int main() {
    int num;
    cin >> num;
    int value, left , right;
    vector<AVLTree::node> arr(num + 1);
    for (int i = 0; i < num; i++) {
        cin >> value >> left >> right;
        arr[i].value = value;
        if (left - 1 != -1) arr[i].left_new = &arr[left - 1];
        else arr[i].left_new = nullptr;
        if (right - 1 != -1) arr[i].right_new = &arr[right - 1];
        else arr[i].right_new = nullptr;
    }

    int x;
    cin >> x;
    AVLTree tree;
    if (num != 0) tree.root = &arr[0];
    tree.add(x);

    cout << num + 1 << '\n';
    tree.print(num + 1);
    return 0;
}
