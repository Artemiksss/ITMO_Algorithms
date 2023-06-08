#include <iostream>

using namespace std;

void heap(int arr[], int len, int i);
void Building_a_pyramid(int arr[], int len);
void heapSort(int arr[], int len);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    int mas[n];
    for(int i = 0; i < n; i++){
        cin >> mas[i];
    }

    heapSort(mas, n);

    for(int i = 0; i < n; i++){
        cout << mas[i] << " ";
    }

    return 0;
}
void heap(int mas[], int len, int i) {
    int bigest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(right < len && mas[right] > mas[bigest]){
        bigest = right;
    }

    if(left < len && mas[left] > mas[bigest]){
        bigest = left;
    }

    if(bigest != i){
        swap(mas[bigest], mas[i]);
        heap(mas, len, bigest);
    }

}

void Building_a_pyramid(int mas[], int len){
    for(int i = len/2; i >=0; i--){
        heap(mas, len, i);
    }
}

void heapSort(int mas[], int len){
    Building_a_pyramid(mas, len);

    while(len > 0){
        swap(mas[0], mas[len-1]);
        len--;
        heap(mas, len, 0);
    }
}

