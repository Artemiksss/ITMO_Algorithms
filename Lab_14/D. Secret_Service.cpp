#include <iostream>
#include <string>
#include <regex>
using namespace std;

regex nameRegex("[A-Z][a-z]+ [A-Z][a-z]+ [A-Z][a-z]+ [0-9]{2} (\\+7\\([0-9]{3}\\)[0-9]{3}-[0-9]{4}|\\+7[0-9]{10}|7[0-9]{10}|8[0-9]{10}|\\+7\\([0-9]{3}\\)-[0-9]{3}-[0-9]{2}-[0-9]{2}) g.[A-Z]{3}, ul.[A-Z][a-z]+, d.[0-9][0-9]+");
bool check(const string& str){
    return regex_match(str, nameRegex);
}

int main() {
    int M;
    string str;
    getline(std::cin, str);
    M = stoi(str);
    string data;
    for (int i = 0; i < M; i++) {
        getline(cin, data);
        cout << (check(data) ? "YES" : "NO") << endl;
    }
    return 0;
}
