#include <iostream>

using namespace std;

void Countnig_Sort(string mas[], int len, int unit) {
    string new_mas[len];
    int c[26] = {0};

    for(int i = 0; i < len; i++) {
        c[(int)mas[i][unit] - 97]++;
    }

    for(int i = 1; i < 26; i++) {
        c[i] = c[i] + c[i-1];
    }

    for(int i = len-1; i >= 0; i--) {
        new_mas[c[(int)mas[i][unit] - 97] - 1] = mas[i];
        c[(int)mas[i][unit] - 97]--;
    }

    for(int i = 0; i < len; i++){
        mas[i] = new_mas[i];
    }
}

void Radix_Sort(string mas[], int len, int str_len, int k) {
    for(int i = str_len-1; i >= 0; i--) {
        Countnig_Sort(mas, len, i);
        k--;
        if(k == 0) {
            for(int j = 0; j < len; j++) {
                cout << mas[j] << "\n";
            }
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;

    string mas[n];
    for(int i = 0; i < n; i++){
        cin >> mas[i];
    }

    Radix_Sort(mas, n, m, k);

    return 0;
}
