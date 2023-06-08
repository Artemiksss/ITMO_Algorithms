#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *next;
};

class Queue{
private:
    Node *head;
public:
    Queue(){
        head = nullptr;
    }
    void push(int d){
        Node *new_node = new Node;
        
        new_node->value = d;
        new_node->next = nullptr;
        
        if(head == nullptr){
            head = new_node;
        }else{
            Node *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
    void pop(){
        if (head != nullptr){
            cout << head->value << "\n";
            head = head->next;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
cin.tie(nullptr);
    Queue queue;
char znak;
    int m, x;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> znak;
        switch (znak) {
            case '+': {
                cin >> x;
                queue.push(x);
                break;
            }
            case '-': {
                queue.pop();
                break;
            }
            default:
                break;
        }
    }
    return 0;
    
}
