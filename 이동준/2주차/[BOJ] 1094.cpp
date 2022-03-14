#include <iostream>
#include <bitset>
using namespace std;

// [BOJ] / 1094. 막대기 / 실버5 / 15분

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);

    //문제에서 막대기 자르는 과정이 2진수로 변환하는 과정이랑 같음 결국엔
    //그니까 만약에 23이면 2진수로는 10111 이니까 1의 갯수만 카운트

    int x; cin >> x;
    bitset<7> b(x); //요기에 7은 7비트라는뜻 = 2진수로 7자리 = 문제 입력이 64보다 작거나 같으니까 2^6=64 최소 7비트 필요
    string s = b.to_string();
    int ret = 0;
    for (int i = 0; i < 7; i++) {
        if (s[i] == '1')
            ret++;
    }
    cout << ret;
}