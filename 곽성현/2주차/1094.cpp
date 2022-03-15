#include <iostream>
using namespace std;
int n;
int main() {
    cin>>n;
   int cnt=1, min=64,sum=64;
    while(sum>n) {
        min=min/2;
        if(sum-min>=n) {
            sum-=min;
            
        } else {
            cnt++;
        }
    }
    cout<<cnt;
}