#include <iostream>
#include "cmath"

using namespace std;

double const eps = 0.00000000001;

bool verification(double a, double b){
    if(abs(a-b) <= eps){
        return true;
    }

    return false;
}

bool less_verification(double a, double b) {
    if((a < b) && !verification(a, b)){
        return true;
    }

    return false;
}

bool more_verification(double a, double b) {
    if((a > b) && !verification(a, b)){
        return true;
    }

    return false;
}

double Gerland(double *arr, int n){
    double minn = 1e9;
    double l = 0;
    double r = arr[0];
    bool higher_floor;

    while (less_verification(l, r)) {
        arr[1] = (l + r) / 2;
        higher_floor = true;

        for (int i = 2; i < n; i++) {
            arr[i] = 2*arr[i-1] - arr[i-2] + 2;
            if (!more_verification(arr[i], 0)) {
                higher_floor = false;
                break;
            }
        }

        if (higher_floor) {
            r = arr[1];
            minn = min(arr[n-1], minn);
        }
        else {
            l = arr[1];
        }
    }

    return minn;
}

int main(){
    int n;
    cin >> n;

    double mas[n];
    cin >> mas[0];

    double rez = Gerland(mas, n);

    printf("%.2f", rez);
    return 0;
}
