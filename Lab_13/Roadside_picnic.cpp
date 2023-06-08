#include <iostream>
#include <vector>


using  namespace std;

class HashTable {
private:
    long long n, m;
    vector<long long> word_one;
    vector<long long> hashes_letters;
    vector<long long> result;

public:
    HashTable() {
        srand(time(0));
    }

    long long generateHash() {
        return (static_cast<long long>(rand()) << 18) | rand();
    }

    bool binarySearch(long long x, vector<long long>& hashes) {
        if (binary_search(hashes.begin(), hashes.end(), x)) {
            return true;
        }
        return false;
    }

    void getInput() {
        cin >> n;
        word_one.resize(n + 1);
        hashes_letters.resize(1000000, 0);

        long long count = 0;

        for (int i = 1; i < n + 1; ++i) {
            long long letter;
            cin >> letter;
            word_one[i] = letter;
            hashes_letters[word_one[i]] = generateHash();
        }

        cin >> m;
        vector<long long> word_two(m + 1);
        for (int i = 1; i < m + 1; ++i) {
            long long letter;
            cin >> letter;
            word_two[i] = letter;
            hashes_letters[word_two[i]] = generateHash();
        }

        for (int i = 1; i < n + 1; ++i) {
            word_one[i] = word_one[i - 1] + hashes_letters[word_one[i]];
        }

        for (int i = 1; i < m + 1; ++i) {
            word_two[i] = word_two[i - 1] + hashes_letters[word_two[i]];
        }

        for (int i = 0; i < n + 1; ++i) {
            for (int j = i; j < n + 1; ++j) {
                result.push_back(word_one[j] - word_one[i]);
            }
        }

        sort(result.begin(), result.end());

        for (int i = 0; i < m + 1; ++i) {
            for (int j = i; j < m + 1; ++j) {
                long long different = word_two[j] - word_two[i];
                if (binarySearch(different, result)) {
                    count = static_cast<long long>(max(static_cast<long long>(j) - i, count));
                }
            }
        }

        cout << count << '\n';
    }
};

int main() {
    HashTable hashtable;
    hashtable.getInput();

    return 0;
}
