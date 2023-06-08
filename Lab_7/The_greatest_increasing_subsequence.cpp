#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num;
    cin >> num;

    vector<int> mas(num);
    for (int i = 0; i < num; ++i)
        cin >> mas[i];

    vector<int> d(num), prev(num);
    for (int i = 0; i < num; ++i) {
        d[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; ++j)
            if ((mas[j] < mas[i]) && (1 + d[j] > d[i])) {
                d[i] = 1 + d[j];
                prev[i] = j;
            }
    }

    int length = d[0], pos = 0;
    for (int i = 0; i < num; ++i)
        if (d[i] > length) {
            length = d[i];
            pos = i;
        }

    vector<int> answer;
    while (pos != -1) {
        answer.push_back(mas[pos]);
        pos = prev[pos];
    }

    reverse(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for (int i : answer){
        cout << i << " ";
    }
    cout << endl;
}
