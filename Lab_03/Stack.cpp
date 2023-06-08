#include <iostream>
#include <stdexcept>
using namespace std;

struct Node{
    int value;
    Node *prev;
};

class Stak{
private:
    Node *upper;
public:
    Stak(){
        upper = nullptr;
    }
    void push(int d){
        Node *new_node = new Node;
        
        new_node->value = d;
        new_node->prev = upper;
        upper = new_node;
    }
    bool empty () const{
        return upper == nullptr;
    }
    int top(){
        if (empty()){
            throw length_error("Stack is empty");
        }
        return upper->value;
    }
    void pop(){
        if (empty()){
            throw length_error("Stack is empty");
        }
        Node *del_node = upper;
        int rez = del_node->value;
        upper = del_node->prev;
        delete del_node;
        cout << rez << "\n";
    }
};

int main(){
    ios::sync_with_stdio(false);
cin.tie(nullptr);
    Stak stak;
char znak;
    int m, x;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> znak;
        switch (znak) {
            case '+': {
                cin >> x;
                stak.push(x);
                break;
            }
            case '-': {
                stak.pop();
                break;
            }
            default:
                break;
        }
    }
    return 0;
    
}
