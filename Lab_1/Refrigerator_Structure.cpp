#include <iostream>
using namespace std;
struct Fridge {
    int milk;
    int meat;
    int cheese;
    int chocolate;
};

int main() {
    Fridge count;
    cout << "Enter the amount of milk" << endl;
    cin >> count.milk;
    cout << "Enter the amount of meat" << endl;
    cin >> count.meat;
    cout << "Enter the amount of cheese" << endl;
    cin >> count.cheese;
    cout << "Enter the amount of chocolate" << endl;
    cin >> count.chocolate;
    cout << "In your fidge: " << endl << count.milk << " litrs of milk; " << endl << count.meat << " kilogram of meat; " << endl << count.cheese << " pieces of cheese; " << endl << count.chocolate << " pieces of chocolate." << endl;
    return 0;
}
