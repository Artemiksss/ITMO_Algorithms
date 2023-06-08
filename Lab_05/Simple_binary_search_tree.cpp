#include <iostream>

using namespace std;

struct Node {
    int x;
    int y;
    Node* left;
    Node* right;
    Node(int nx) {
           x = nx;
           y = rand() * rand();
           left = nullptr;
           right = nullptr;
       }
};

void split(Node* root, Node*& left, Node*& right, int num) {
    if (root == nullptr) {
        left = nullptr;
        right = nullptr;
        return;
    }

    if (root->x < num) {
        split(root->right, root->right, right, num);
        left = root;
    } else {
        split(root->left, left, root->left, num);
        right = root;
    }
};

void add(Node*& root, Node* left, Node* right) {
    if (left == nullptr || right == nullptr) {
        if (right == nullptr){
            root = left;
        }
        else{
            root = right;
        }
        return;
    }

    if (left->y > right->y) {
        add(left->right, left->right, right);
        root = left;
    } else {
        add(right->left, left, right->left);
        root = right;
    }
}

void insert(Node*& root, Node* value) {
    if (root == nullptr) {
        root = value;
        return;
    }

    if (root->y > value->y) {
        if (value->x < root->x){
            insert(root->left, value);
        }
        else {
            insert(root->right, value);
        }
        return;
    }

    split(root, value->left, value->right, value->x);
    root = value;
}

void remove(Node*& root, int num) {
    if (root == nullptr) return;

    if (num < root->x) {
        remove(root->left, num);
    } else if (num > root->x) {
        remove(root->right, num);
    } else {
        add(root, root->left, root->right);
    }
}

bool exists(Node*& root, int num) {
    if (root == nullptr) {
        return false;
    }

    if (num == root->x) {
        return true;
    }

    if (num < root->x) {
        return exists(root->left, num);
    } else {
        return exists(root->right, num);
    }
}


Node* prev(Node*& root, int num) {
    Node* current = root, * successor = nullptr;

    while (current != nullptr) {
        if (current->x < num) {
            successor = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }

    return successor;
}

Node* next(Node*& root, int num) {
    Node* current = root, * successor = nullptr;

    while (current != nullptr) {
        if (current->x > num) {
            successor = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return successor;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    int number;
    Node* value;
    Node* root = nullptr;

    while (cin >> str >> number) {
        if (str[0] == 'i') {
            value = new Node(number);
            if (!exists(root, number)){
                insert(root, value);
            }
                
                continue;
        }
        if (str[0] == 'e') {
            if (exists(root, number)){
                cout << "true";
            }
            else{
            cout << "false";
        }
            cout << "\n";
            continue;
        }
        if (str[0] == 'd') {
            if (exists(root, number)){
                remove(root, number);
            }
            continue;
        }
        if (str[0] == 'n') {
            value = next(root, number);
            if (value == nullptr){
                cout << "none";
            }
            else {
                cout << value->x;
            }
            cout << "\n";
            continue;
        }
        if (str[0] == 'p') {
            value = prev(root, number);
            if (value == nullptr){
                cout << "none";
            }
            else{
                cout << value->x;
            }
            cout << "\n";
        }
    }

    return 0;
}


