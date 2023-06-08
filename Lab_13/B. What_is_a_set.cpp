#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10000000;


long long hash_function(long long key, int size) {
    return key % size;
}

int main() {
    long long n;
    cin >> n;

    vector<long long> table(SIZE, -1);

    for (int i = 0; i < n; i++) {
        long long number1;
        cin >> number1;
        long long index = hash_function(number1, SIZE);
        table[index] = number1;
    }

    bool equality_of_sets = true;
    for (int i = 0; i < n; i++) {
        long long number2;
        cin >> number2;
        long long index = hash_function(number2, SIZE);
        if (table[index] != number2) {
            equality_of_sets = false;
            break;
        }
    }

    if (equality_of_sets) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
