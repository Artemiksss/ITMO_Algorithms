#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++){
        cin >> arr[i];
    }
    int temp = arr[num - 1];
    for (int i = num - 1; i > 0; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
    for (int i = 0; i < num; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
