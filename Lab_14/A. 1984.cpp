#include <iostream>
#include <vector>

using namespace std;

int main() {
    string firstWord, secondWord;
    cin >> firstWord;
    cin >> secondWord; 
    vector<int> position;

    int count = 0;
    int index = 0;

    while (index <= firstWord.length() - secondWord.length()) {
        bool match = true;
        for (int j = 0; j < secondWord.length(); j++) {
            if (firstWord[index + j] != secondWord[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            count++;
            position.push_back(index);
        }
        index++;
    }

    cout << count << std::endl;
    for (int i : position) {
        cout << i << " ";
    }
    cout << std::endl;

    return 0;
}

