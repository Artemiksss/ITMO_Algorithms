#include <iostream>
using namespace std;
void quick_sort(int *mas, int first, int last);
int main() {
    int num1;
    cin >> num1;
    int mas1[num1];
    for (int i = 0; i < num1; ++i){
        cin >> mas1[i];
    }
    quick_sort(mas1, 0, num1 - 1);
    int num2;
    cin >> num2;
    int mas2[num2];
    for (int i = 0; i < num2; ++i){
        cin >> mas2[i];
    }
    quick_sort(mas2, 0, num2 - 1);
    int *p1 = mas1, *p2 = mas2;
    int max1 = -1000000001;
    for (int i = 0; i < num1; i++){
        if (mas1[i] > max1){
            max1 = mas1[i];
        }
    }
    int min1 = 1000000001;
    for (int i = 0; i < num1; i++){
        if (mas1[i] < min1){
            min1 = mas1[i];
        }
    }
    int max2 = -1000000001;
    for (int i = 0; i < num2; i++){
        if (mas2[i] > max2){
            max2 = mas2[i];
        }
    }
    int min2 = 1000000001;
    for (int i = 0; i < num2; i++){
        if (mas2[i] < min2){
            min2 = mas2[i];
        }
    }
    int min_len_mas;
    if (num1 < num2){
        min_len_mas = num1;
    }else{
        min_len_mas = num2;
    }
    
    int rezalt = 1;
    int point1 = 1;
    int point2 = 1;
    
    if (min1 == min2 && max1 == max2){
        while (point1 < num1 && point2 < num2){
            if (mas1[point1] == mas2[point2]){
                point1 = point1 + 1;
                point2 = point2 + 1;
                rezalt = rezalt + 1;
            }
            else if (mas1[point1] > mas2[point2]){
                if (mas2[point2] > mas1[point1 - 1]){
                    cout << "NO";
                    return 0;
                }
                point2 = point2 + 1;
            }
            else if (mas1[point1] < mas2[point2]){
                if (mas1[point1] > mas2[point2 - 1]){
                    cout << "NO";
                    return 0;
                }
                point1 = point1 + 1;
            }
        }
        cout << "YES";
    }else{
        cout << "NO";
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
