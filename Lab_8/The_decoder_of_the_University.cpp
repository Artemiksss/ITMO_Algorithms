#include <iostream>
#include <string>


using namespace std;

int main(){


    int t = 0;
    cin >> t;

    for (int n = 0; n < t; ++n) {

        string str1, str2;

        cin >> str1;
        str2 = str1;

        int incorrect_bit_position = 0;
        for (int bit_position = 1; bit_position <= str2.size(); bit_position <<= 1) {
            int k = bit_position - 1;
            int current_bit_position = bit_position;
            int count = 0;

            for (int j = k; j < str2.size(); j = ((j - k + 1) % bit_position == 0) ? j += bit_position + 1 : j += 1) {
                if (j + 1 == current_bit_position) {
                    current_bit_position <<= 1;
                    continue;
                } else {

                    if (str2[j] == '1') count++;

                }
            }
            if (count % 2 == 0){
                str2[k] = '0';
            }else{
                str2[k] = '1';
            }

            if (str2[k] != str1[k]) {
                incorrect_bit_position += bit_position;
            }
        }

        if (incorrect_bit_position > 0) {
            incorrect_bit_position--;
            if (str1[incorrect_bit_position] == '1'){
                str1[incorrect_bit_position] = '0';
            }else{
                str1[incorrect_bit_position] = '1';
            }
        }

        int pow = 4;
        for (int i = 2; i < str1.size(); ++i) {
            if (i + 1 == pow)
                pow <<= 1;
            else
                cout << str1[i];
        }
        cout << '\n';

    }

    return 0;
}