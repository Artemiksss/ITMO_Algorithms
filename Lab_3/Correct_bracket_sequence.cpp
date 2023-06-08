#include <iostream>
#include <stdexcept>
#include <string>
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
    void push(char d){
        Node *new_node = new Node;
        
        new_node->value = d;
        new_node->prev = upper;
        upper = new_node;
    }
    int peek(){
            if (!empty())
                return upper->value;
            else
                return 0;;
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
    char pop(){
        if (empty()){
            throw length_error("Stack is empty");
        }
        Node *del_node = upper;
        int rez = del_node->value;
        upper = del_node->prev;
        delete del_node;
        return rez;
    }
};

int main(){
    string line;
    while (cin >> line) {
        Stak stak;
        for (int i = 0; i < size(line); i++){
            if (line[i] == '(' || line[i] == '{' || line[i] == '['){
                stak.push(line[i]);
            }else{
                char sym;
                sym = stak.peek();
                if ((sym == '(' && line[i] == ')') || (sym == '{' && line[i] == '}') || (sym == '[' && line[i] == ']')){
                    stak.pop();
                }else{
                    stak.push(line[i]);
                    }
                }
            }
        if (stak.empty()){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
return 0;
}
