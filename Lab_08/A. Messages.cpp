#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct elem_RLE{
    char symbol{};
    int count = 0;
};
void delta_Symbol(string& str1, elem_RLE arr[]){
    int str_idx = 0;
    int arr_idx = 0;
    while (str_idx < str1.length()) {
        arr[arr_idx].symbol = str1[str_idx];
        str_idx++;
        while (str_idx < str1.length() && isdigit(str1[str_idx])) {
            arr[arr_idx].count = arr[arr_idx].count*10 + (int(str1[str_idx]) - 48);
            str_idx++;
        }
        arr_idx++;
    }
}
int count_alfa(const string& str){
    int countt = 0;
    for (char i : str){
        if (isalpha(i)){
            countt += 1;
        }
    }
    return countt;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string str1, str2;
    int delta = 0;
    cin >> str1;
    cin >> str2;
    int isalpha_str1 = count_alfa(str1);
    int isalpha_str2 = count_alfa(str2);
    elem_RLE arr_one[isalpha_str1];
    elem_RLE arr_two[isalpha_str2];
    delta_Symbol(str1, arr_one);
    delta_Symbol(str2, arr_two);


    int idx_1 = 0;
    int idx_2 = 0;

    while( idx_1 < isalpha_str1 && idx_2 < isalpha_str2) {
        if(arr_one[idx_1].symbol != arr_two[idx_2].symbol) {
            if(arr_two[idx_2].count < arr_one[idx_1].count) {
                delta += arr_two[idx_2].count;
                arr_one[idx_1].count -= arr_two[idx_2].count;
                idx_2++;
            } else if(arr_two[idx_2].count > arr_one[idx_1].count) {
                delta += arr_one[idx_1].count;
                arr_two[idx_2].count -= arr_one[idx_1].count;
                idx_1++;
            } else {
                delta += arr_one[idx_1].count;
                idx_1++;
                idx_2++;
            }
        } else {
            if(arr_two[idx_2].count < arr_one[idx_1].count) {
                arr_one[idx_1].count -= arr_two[idx_2].count;
                idx_2++;
            } else if (arr_two[idx_2].count > arr_one[idx_1].count) {
                arr_two[idx_2].count -= arr_one[idx_1].count;
                idx_1++;
            } else {
                idx_1++;
                idx_2++;
            }
        }

        if(delta >= k)
            break;
    }
    if (delta > k) {
        cout << "No";
    }else{
        cout << "Yes";
    }

    return 0;
}
