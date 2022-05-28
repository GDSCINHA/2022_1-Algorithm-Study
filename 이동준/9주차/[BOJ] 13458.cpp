#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// [BOJ] / 13458. 시험 감독 / 브론즈 2 / 10분

int main() {
    int n; cin >> n;
    vector<long long>shj;
    for (int i = 0; i < n; i++) {
        long long tmp; cin >> tmp;
        shj.push_back(tmp);
    }
    int b, c; cin >> b >> c;
    long long ret = n;
    for (int i = 0; i < n; i++) {
        long double now = shj[i] - b; //자료형 개같은거..
        if (now > 0) {
            ret += ceil(now / c);
        }
    }
    cout << ret;
}