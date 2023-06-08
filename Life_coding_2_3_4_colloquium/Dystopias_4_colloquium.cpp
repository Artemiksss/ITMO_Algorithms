#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;
const long long BASE = 31;

class StringChecker {
private:
    string str;
    size_t length;
    vector<long long> prefixHash1, powersOfBase, prefixHash2;

public:
    StringChecker(const string& inputString) {
        str = inputString;
        length = str.size();
        str += str;
        powersOfBase.resize(2 * length);

        prefixHash1.resize(2 * length, 0);
        prefixHash1[0] = str[0] - 'a' + 1;
        powersOfBase[0] = 1;
        for (size_t i = 1; i < 2 * length; ++i) {
            prefixHash1[i] = (prefixHash1[i - 1] * BASE + (str[i] - 'a' + 1)) % MOD;
            powersOfBase[i] = (powersOfBase[i - 1] * BASE) % MOD;
        }

        prefixHash2.resize(2 * length, 0);
        prefixHash2[2 * length - 1] = str[2 * length - 1] - 'a' + 1;
        for (int i = 2 * length - 2; i >= 0; --i) {
            prefixHash2[i] = (prefixHash2[i + 1] * BASE + (str[i] - 'a' + 1)) % MOD;
        }
    }

    bool isCyclicSubstringPresent() {
        for (size_t i = 0; i + length - 1 < 2 * length; ++i) {
            if (getHash1(i, i + length - 1) == getHash2(i, i + length - 1)) {
                return true;
            }
        }

        return false;
    }

private:
    long long getHash1(size_t left, size_t right) {
        if (left == 0) return prefixHash1[right] % MOD;
        return (prefixHash1[right] - prefixHash1[left - 1] * powersOfBase[right - left + 1] + MOD * MOD) % MOD;
    }

    long long getHash2(size_t left, size_t right) {
        if (right + 1 == 2 * str.size()) return prefixHash2[left] % MOD;
        return (prefixHash2[left] - prefixHash2[right + 1] * powersOfBase[right - left + 1] + MOD * MOD) % MOD;
    }
};

int main() {
    string userInput;
    cin >> userInput;

    StringChecker checker(userInput);
    if (checker.isCyclicSubstringPresent()) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
