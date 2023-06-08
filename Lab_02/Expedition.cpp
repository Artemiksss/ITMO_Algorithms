#include <iostream>
using namespace std;
void quick_sort(int *mas, int first, int last);
int main() {
    int n, m;
    cin >> n >> m;
    int mas1[n * m];
    for (int i = 0; i < n * m; i++){
        cin >> mas1[i];
    }
    quick_sort(mas1, 0, n * m - 1);
    int num;
    cin >> num;
    int mas2[num];
    for (int i = 0; i < num; i++){
        cin >> mas2[i];
    }
    quick_sort(mas2, 0, num - 1);
    int k = 0;
    int i = n * m - 1;
    int j = num - 1;
    for (int s = n * m; s > 0;s--){
        while (i >= 0 && j >= 0){
            if (mas1[i] >= mas2[j]){
                k++;
                i--;
                j--;
                
            }
            else
                j--;
        }
    }
    cout << k << endl;
    return 0;
}


void quick_sort(int *mas, int first, int last){
    if (first < last){
        int left = first;
        int right = last;
        int mid = mas[(left + right) / 2];
        do{
            while (mas[left] < mid) {
                left++;
            }
            while (mas[right] > mid) {
                right--;
            }
            if (left <= right){
                int tmp = mas[left];
                mas[left] = mas[right];
                mas[right] = tmp;
                left++;
                right--;
            }
        }while(left < right);
        quick_sort(mas, first, right);
        quick_sort(mas, left, last);
    }
    return;
}
