#include <iostream>
using namespace std;
void quick_sort(int *mas, int first, int last);
int main() {
    int num;
    cin >> num;
    int mas[num];
    for (int i = 0; i < num; i++){
        cin >> mas[i];
    }
    quick_sort(mas, 0, num - 1);
    for (int i = 0; i < num; i++){
        cout << mas[i] << " ";
    }
    cout << endl;
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
