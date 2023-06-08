#include <iostream>
using namespace std;
int main() {
    int mas[1001];
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cin >> mas[i];
    }
    int number;
    int place;
    cin >> number >> place;
    for (int i = num; i >= place; --i) {
        mas[i] = mas[i - 1];
    }
    mas[place - 1] = number;
    num = num + 1;
    for (int i = 0; i < num; ++i) {
        cout << mas[i] << " ";
    }
    cout << endl;
    return 0;
}