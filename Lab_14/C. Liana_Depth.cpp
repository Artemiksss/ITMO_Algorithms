#include <iostream>
#include <string>

using namespace std;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int N, M;
    cin >> N >> M;
    string song;
    cin >> song;

    int count = 0;

    for (int i = 0; i < M; i++) {
        int start1, start2, length;
        cin >> start1 >> start2 >> length;
        bool flag = true;

        for (int j = 0; j < length; j++) {
            if (song[start1 - 1 + j] != song[start2 - 1 + j]) {
                flag = false;
                break;
            }
        }

        if (flag)
            count++;
    }

    cout << count << endl;

    return 0;
}
