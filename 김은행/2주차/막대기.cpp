#include <iostream>

using namespace std;
 
int main() {
    int x;
    cin >> x;
 
    int count = 1, min = 64, sum = 64;
    
    while(sum > x) {
        min = min / 2;
        
        if(sum - min >= x)
            sum -= min;
        else
            count++;
    }
 
    cout << count << "\n";
    
    return 0;
}