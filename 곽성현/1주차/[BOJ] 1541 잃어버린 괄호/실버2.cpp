#include <iostream>
#include <cstring>
using namespace std;
string str,num;
int ans;
int main() {
    bool minus = false;
    cin >> str;

    for (int i = 0; i <= str.size(); i++) {
        if (str[i] == '+' || str[i] == '-' || i==str.size()) {
            if (minus) {
                ans -= stoi(num);
                num = "";
            }
            else {
                ans += stoi(num);
                num = "";
            }
        }
        else {
            num += str[i];
        }
        
        
        if (str[i] == '-') {
            minus = true;
        }
    }
    cout << ans;
}