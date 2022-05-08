#include <iostream>

using namespace std;

int arr[20];


int main() {
    arr[1] = 1;
    
    int a;
    cin >> a;
    
    for (int i = 2; i <= a; i++) {
        arr[i] = arr[i - 2] + arr[i - 1];
    }
    
    cout << arr[a] << endl;
    
    return 0;
}