#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x;
    scanf("%d", &x);
    
    vector<int> d(x + 1);
    
    for (int i = 2; i <= x; i++) {
        d[i] = d[i - 1] + 1;
        
        if (i % 2 == 0) {
            d[i] = min(d[i], d[i / 2] + 1);
        }
        if (i % 3 == 0) {
            d[i] = min(d[i], d[i / 3] + 1);
        }
    }
    
    printf("%d", d[x]);
    
    return 0;
}