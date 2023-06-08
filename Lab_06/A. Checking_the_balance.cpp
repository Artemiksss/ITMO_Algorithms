#include <iostream>

using namespace std;

struct Node {
    int left, right;
    int height;
};

Node mas[200001];
int mas_balance[200001];
int balance(int i);


int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int trash, x, y;
        cin >> trash >> x >> y;
        mas[i] = {x, y, 1};
    }

    for (int i = n; i > 0; --i) {
        if (1 <= i && i <= 200000){
            mas_balance[i] = balance(i);
            mas[i].height += max(mas[mas[i].left].height, mas[mas[i].right].height);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << mas_balance[i] << "\n";
    }
    return 0;
}


int balance(int i) {
    int left_h = mas[i].left;
    int right = mas[i].right;
    int rezalt = -mas[left_h].height + mas[right].height;
    return rezalt;
}
