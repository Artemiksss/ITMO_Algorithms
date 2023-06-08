#include <vector>
#include <iostream>
#include <map>
using namespace std;


class Priority_queue{
private:
    int size;
    vector<vector<int>> mas;
    map <int, int> history;
public:
    Priority_queue(){
        size = 0;
    }
    void add(int a,int num){
        mas.push_back({a, num});
        history[num] = size;
        up(size);
        size += 1;
    }
    void down(int n){
        int t;
        while((n*2 + 1 < size)){
            if(n*2 + 2 >= size){
                t = n*2 + 1;
            }else {
                if (mas[n * 2 + 1] > mas[n * 2 + 2]) {
                    t = n * 2 + 2;
                } else {
                    t = n * 2 + 1;
                }
            }
            if(mas[n] > mas[t]){
                swap(mas[t], mas[n]);
                swap(history[mas[t][1]], history[mas[n][1]]);
                n = t;
            } else{
                break;
            }
        }
    }


    void up(int n){
        while(((n + (n % 2))/ 2 > 0) and (mas[(n + (n % 2)) / 2 - 1]) > mas[n]){
            swap(mas[(n + (n % 2)) / 2 - 1], mas[n]);
            swap(history[mas[(n + (n % 2)) / 2 - 1][1]], history[mas[n][1]]);
            n = (n + (n % 2)) / 2 - 1;
        }
    }

    void extract_min(){
        if(size > 0){
            cout << mas[0][0] << '\n';
            swap(mas[0],mas[size - 1]);
            swap(history[mas[0][1]], history[mas[size - 1][1]]);
            size -= 1;
            mas.pop_back();
            down(0);
        }else{
            cout << "*\n";
        }
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout << mas[i][0] << ' ';
        }
    }

    void decrease_key(int x, int y){
        mas[history[x]][0] = y;
        up(history[x]);
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Priority_queue q;
    char a[30];
    int c,b;
    int num = 1;
    while(cin >> a){
        if(a[0] == 'p'){
            cin >> c;
            q.add(c,num);
        }else if(a[0] == 'e'){
            q.extract_min();
        }else{
            cin >> b >> c;
            q.decrease_key(b,c);
        }
        num++;
    }
    return 0;
}
