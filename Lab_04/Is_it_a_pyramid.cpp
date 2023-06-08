#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
   cin.tie(nullptr);

    int num;
    cin >> num;
    int mas[num];
    for (int i = 0; i < num; i++){
        cin >> mas[i];
    }
    bool flag = true;
    for (int i = 0; i < (num - 1) / 2; i++){
        if ((mas[i] <= mas[2 * i + 1]) && (mas[i] <= mas[2 * i + 2])){
            flag = true;
        }else{
            flag = false;
            break;
        }
    }
    if (flag){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}
