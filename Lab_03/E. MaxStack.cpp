#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value;
    int max;
    Node* next;
};

class Stak {
private:
    Node* head;
public:
    Stak() {
        head = nullptr;
    }


    void pop() {
        if (head != nullptr) {
            head = head->next;
        }
    }
    void push(int x) {
        Node* new_node = new Node;
        new_node->value = x;
        new_node->next = head;

        if (head)
        {
            if (new_node->value > head->max)
                new_node->max = new_node->value;
            else
                new_node->max = head->max;
        }
        else
        {
            new_node->max = x;
        }

        head = new_node;
    }

    int top()
    {
        return head->max;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Stak stack;
    int num, k;
    string znak;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> znak;
        if (znak == "+") {
            cin >> k;
            stack.push(k);
        }
        else if (znak == "-") {
            stack.pop();
        }
        else if (znak == "max") {
            cout << stack.top() << "\n";
        }

    }
    return 0;
}
