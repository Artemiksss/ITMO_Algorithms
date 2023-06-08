#include <iostream>
using namespace std;
int main() {
    int n, k;
    int *mas;
    cin >> k >> n;
    mas = new int[n + 1];
    mas[0] = 1;
    long long summa = 1;
    for (int i = 1; i <= n; ++i) {
        mas[i] = summa;
        if (k <= i) {
            summa = 1000000007 + summa - mas[i - k];
        }
        summa = (summa + mas[i])  % 1000000007;
    }
    cout << mas[n];
    delete[] mas;
    return 0;
}
