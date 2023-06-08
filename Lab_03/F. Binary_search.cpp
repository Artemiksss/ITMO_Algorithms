#include <iostream>
using namespace std;

int Binary_Search_l(int *nums, int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high)/2;

        if (target <= nums[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if(target != nums[high+1]){
        return -1;
    }

    return high+2;
}

int Binary_Search_r(int *nums, int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high)/2;

        if (target < nums[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if(target != nums[low-1]){
        return -1;
    }

    return low;
}

int main()
{
    int num;
    cin >> num;

    int mas[num];

    for (int i = 0; i < num; i++){
        cin >> mas[i];
    }

    int count;
    cin >> count;

    int elements[count];

    for (int i = 0; i < count; i++){
        cin >> elements[i];
    }

    for (int element = 0; element < count; element++){
        int index = Binary_Search_r(mas, num, elements[element]);

        if (index != -1)
        {
            cout << Binary_Search_l(mas, num, elements[element]) << " " << Binary_Search_r(mas, num, elements[element]) << "\n";
        }
        else {
            cout << "-1 -1\n";
        }
    }
    return 0;
}