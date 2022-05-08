#include <iostream>

using namespace std;

int arr[13];

int main() {
    arr[0] = 1;
    
    int a;
    cin >> a;
    
    for (int i = 1; i <= a; i++) {
        arr[i] = arr[i - 1] * i;
    }
    
    cout << arr[a] << endl;
    
    return 0;
}