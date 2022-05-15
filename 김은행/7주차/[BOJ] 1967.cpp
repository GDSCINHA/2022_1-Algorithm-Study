/*
온라인에서 정답 코드보고 이해했습니다.
*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

bool visited[10001];
vector<pair<int, int>> node[10001];

int ans = 0;       // 지름 길이
int end_point = 0; // 지름에 해당하는 끝점

void dfs(int point, int length) {
    
    if (visited[point])
        return;
    
    visited[point] = true; // 방문 처리
    
    if (ans < length) {
        ans = length;
        end_point = point;
    }
    
    for (int i = 0; i < node[point].size(); i++) {
        dfs(node[point][i].first, length + node[point][i].second);
    }
}

int main() {
    int n;
    cin >> n;
    
    int parent, child, length;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &parent, &child, &length);
        node[parent].push_back(make_pair(child, length));
        node[child].push_back(make_pair(parent, length));
    }
    
    // 가장 멀리 있는 정점(end_point) 구하기
    dfs(1, 0);
    
    ans = 0;
    memset(visited, false, 10001 * sizeof(bool));
    
    // end_point와 가장 멀리 있는 정점과의 거리 구하기
    dfs(end_point, 0);
    
    cout << ans << endl;    // 정답 출력
    
    return 0;
}