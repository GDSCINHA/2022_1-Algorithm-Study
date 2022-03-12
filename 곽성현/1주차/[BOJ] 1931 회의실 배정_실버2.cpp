#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,t,ans;
int main() {

    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) {
        if (t <= a[i].second) {
            t = a[i].first;
            ans++;
        }
    }
    cout<<ans;

}