#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    cin >> num;
    int root,left,right;
    int maxx = 0;
    vector<int> mas;
    for(int i = 0; i < num; i++){
        mas.push_back(0);
    }
    if(num == 0){
        cout << 0;
        return 0;
    }
        for(int i = 0; i < num; i++){
            cin >> root >> left >> right;
            if(left != 0) {
                mas[left - 1] = (mas[left - 1]) + (1 + mas[i]);
                maxx = max(mas[left - 1], maxx);
            }
            if(right != 0) {
                mas[right - 1] = (mas[right - 1]) + (1 + mas[i]);
                maxx = max(mas[right - 1], maxx);
            }
        }
    cout << maxx + 1 << "\n";

    return 0;
}
