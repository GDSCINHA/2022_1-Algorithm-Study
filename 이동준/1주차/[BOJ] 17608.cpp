#include <iostream>
#include <vector>
using namespace std;

// [BOJ] / 17608. 막대기 / 브론즈2 / 5분

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);

    int n, ret = 1; cin >> n;
    int mdg[100000];
    for (int i = 0; i < n; i++) {
        cin >> mdg[i];
    }
    int tmp = mdg[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (tmp < mdg[i]) {
            tmp = mdg[i]; ret++;
        }
    }
    cout << ret;
}