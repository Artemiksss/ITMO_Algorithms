#include <iostream>
#include <vector>
using namespace std;

vector<int> calculateValues(const string& str) {
    int n = str.length();
    vector<int> values(n, 0);

    for (int i = 1; i < n; i++) {
        int j = values[i - 1];
        while (j > 0 && str[i] != str[j])
            j = values[j - 1];
        if (str[i] == str[j])
            j++;
        values[i] = j;
    }

    return values;
}

int main() {
    string str;
    cin >> str;

    vector<int> values = calculateValues(str);

    for (int i = 0; i < str.length(); i++) {
        cout << values[i] << " ";
    }
    cout << endl;

    return 0;
}
