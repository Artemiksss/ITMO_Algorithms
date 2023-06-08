#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++){
        mas[i] = i + 1;
    }
    for (int i = 2; i < n; i++){
        
        int tmp = mas[i];
        mas[i] = mas[i/2];
        mas[i/2] = tmp;
    }
    for (int i = 0; i < n; i++){
        cout << mas[i] << " ";
    }
    cout << endl;
    return 0;
}