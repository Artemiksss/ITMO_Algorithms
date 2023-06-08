#include <iostream>
using namespace std;
struct Node {
    string data;
    Node *left;
    Node *right;
    Node(string Data) : data(Data), left(nullptr), right(nullptr) {}
};
bool checking(Node *&r, string x);
Node *insert(Node *&r, string x);
void result(Node* tree, Node* x, Node* y);
int kolich;

int main() {
    int num;
    cin >> num;
    string task;
    Node* one = nullptr;
    Node* two = nullptr;
    Node* three = nullptr;
    for(int i = 0; i < num; i++){
        cin >> task;
        one = insert(one, task);
    }
    for(int i = 0; i < num; i++){
        cin >> task;
        two = insert(two, task);
    }
    for(int i = 0; i < num; i++){
        cin >> task;
        three = insert(three, task);
    }
    kolich = 0;
    result(one, two, three);
    cout << kolich << ' ';
    kolich = 0;
    result(two, one, three);
    cout << kolich << ' ';
    kolich = 0;
    result(three, two, one);
    cout << kolich << ' ';
    kolich = 0;
}

bool checking(Node *&r, string x){
    if (r == nullptr){
        return false;
    }
    if (r ->data == x){
        return true;
    }
    if (r ->data > x){
        return checking(r ->left, x);
    } else{
        return checking(r ->right, x);
    }
}

Node *insert(Node *&r, string x){
    if (r == nullptr){
        r = new Node(x);
        r ->data = x;
        r ->left = nullptr;
        r ->right = nullptr;
    } else if (x < r -> data) {
        insert(r->left, x);
    }else if (x > r -> data) {
        insert(r->right, x);
    }
    return r;
}

void result(Node* tree, Node* x, Node* y){
    int point = 0;
    if(tree != nullptr){
        if(checking(x,tree->data)){
            point++;
        }
        if(checking(y,tree->data)) {
            point++;
        }
        if(point == 0){
            kolich += 3;
        }else if(point == 1){
            kolich += 1;
        }else{
            kolich += 0;
        }
        result(tree->left, x, y);
        result(tree->right, x, y);
    }
}
