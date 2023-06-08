#include <vector>
#include <iostream>
#include <string>
using namespace std;


struct Node{
    int data;
    Node *next;
};

class Stak{
private:
    Node *head;
    int len;
public:
    Stak(){
        head = NULL;
        len = 0;
    }
    void push(int a){
        Node *t = new Node;
        t->data = a;
        t->next = head;
        head = t;
        len++;
    }
    void pop(){
        head = head->next;
        len--;
    }
    void print(){
        Node * t;
        t = head;
        while(t->next != NULL){
            cout << t->data << ' ';
            t = t->next;
        }
        cout << t->data << '\n';
    }
    int start(){
        return head->data;
    }
    int size(){
        return len;
    }
    void clear(){
        head = NULL;
        len = 0;
    }
};


int main(){
    Stak s;
    string a;
    getline(cin, a);
    int t1,t2;
    for(int i = 0; i < a.size(); i += 2){
        if(a[i] != '+' and a[i] != '-' and a[i] != '*'){
            s.push(a[i] - '0');
        }else{
            t1 = s.start();
            s.pop();
            t2 = s.start();
            s.pop();
            if(a[i] == '+'){
                s.push(t1 + t2);
            }else if(a[i] == '-'){
                s.push(t2 - t1);
            }else{
                s.push(t1 * t2);
            }
        }
    }
    cout << s.start() << "\n";
    return 0;

}
