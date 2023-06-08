#include <iostream>
#include <vector>

using namespace std;

int print(vector<int> countt, int s){
    for (int i = s; i >= 0; --i){
        if (countt[i] == 1){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}

int main() {
    int s, n;
    cin >> s >> n;
    vector<int> mas;
    vector<int> countt(10000000, 0);
    countt[0] = 1;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        mas.push_back(temp);
    }

    for(int i: mas){
        for (int j = s; j > i - 1; --j)
            if (countt[j - i] == 1)
                countt[j] = 1;
    }
    
    print(countt, s);
}
