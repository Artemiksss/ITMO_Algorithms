#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < pow(2, n); i++) {
        int gray = i ^ (i >> 1);
        bitset<32> b(gray);
        cout << b.to_string().substr(32-n) << endl;
    }

    return 0;
}