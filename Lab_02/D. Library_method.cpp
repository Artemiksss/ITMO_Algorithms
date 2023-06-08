#include <iostream>
using namespace std;
int main(){
    int num;
    cin >> num;
    int mas[1001];
    for (int i = 0; i < num; i++){
        cin >> mas[i];
    }
    for (int i = 1; i < num; i++){
        int key = mas[i];
        int j = i - 1;
        int flag = 0;
        while (j >= 0 && mas[j] > key) {
            mas[j + 1] = mas[j];
            mas[j] = key;
            j--;
            flag = 1;
        }
        if (flag == 1){
            for (int i = 0; i < num; i ++){
                cout << mas[i] << " ";
            }
            cout << endl;
      }
    }
    cout << endl;
}