#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // insert code here...
    int n,arr[100001],cnt=0,max=0;
   
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
       
    }
   
    
    for(int i=n-1;i>=0;i--){
        if(arr[i]>max){
            cnt++;
            max=arr[i];
        }
    }
    cout<<cnt;
}
