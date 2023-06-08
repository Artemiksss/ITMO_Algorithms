#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    vector<int> z_values, sequence;

    int length, m;
    cin >> length >> m;
    sequence.resize(2 * length + 1);
    for (int i = 0; i < length; ++i) {
        cin >> sequence[i];
        sequence[2 * length - i] = sequence[i];
    }

    int seq_size = sequence.size();
    z_values.resize(seq_size + 1);
    z_values[0] = seq_size;
    int left = 0;
    int right = 0;
    for (int i = 1; i < seq_size; ++i) {
        if (i <= right) {
            z_values[i] = min(right - i + 1, z_values[i - left]);
        }
        while (i + z_values[i] < seq_size && sequence[z_values[i]] == sequence[i + z_values[i]]) {
            z_values[i]++;
        }
        if (i + z_values[i] - 1 > right) {
            left = i;
            right = i + z_values[i] - 1;
        }
    }

    set<int> result_set;
    result_set.insert(length);
    for (int i = 2 * length; i > length; --i) {
        if (z_values[i] + i == 2 * length + 1 && (z_values[i] % 2 == 0)) {
            result_set.insert(length - z_values[i] / 2);
        }
    }
    for (set<int>::iterator it = result_set.begin(); it != result_set.end(); it++)
        std::cout << *it << " ";

    return 0;
}
