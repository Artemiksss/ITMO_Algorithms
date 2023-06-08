#include <iostream>
#include <vector>

using namespace std;
const int Size = 10000000;

int n;

int hash_function(int chair, int i){
    return chair - i + n;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    cin >> n;
    vector<int> Chairs(n);
    vector<int> Chairs_Count(Size, 0);

    for (int i = 0; i < n; i++) {
        cin >> Chairs[i];
    }

    int result_count = 0;
    for (int i = 0; i < n; i++) {
        int key = hash_function(Chairs[i], i);
        Chairs_Count[key]++;
        result_count += Chairs_Count[key] - 1;
    }

    cout << result_count;

    return 0;
}
