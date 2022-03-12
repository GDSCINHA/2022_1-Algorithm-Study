#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// [BOJ] / 1931. 회의실 배정 / 실버2 / 25분

bool cmp(pair<int,int>p1,pair<int,int>p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);

    //뭐 시작시간으로 정렬하든 끝시간으로 정렬하든 상관 없음
    //아무튼 나는 시작시간 기준으로 정렬함
    //시작시간 기준 정렬에서 가장 늦게 끝나는 놈부터 확인
    //만약에 끝시간으로 정렬했으면 가장 먼저 시작하는놈부터 확인
    //계속 뒤로 가면서 겹치지 않으면 최종 갯수에 추가

    int N; cin >> N;
    vector<pair<int, int>>v;
    for (int i = 0; i < N; i++) {
        int start, end; cin >> start >> end;
        v.push_back(make_pair(start, end));
    }
    sort(v.begin(), v.end(),cmp);
    int ret = 1, tmp = v[N - 1].first;
    for (int i = N - 2; i >= 0; i--) {
        if (v[i].second <= tmp) {
            ret++;
            tmp = v[i].first;
        }
    }
    cout << ret;
}