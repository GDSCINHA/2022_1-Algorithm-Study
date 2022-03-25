#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

// 전역변수 지역에 선언하여 0으로 초기화
int n, m;
int graph[101][101];

// 상하좌우 모두 확인하는 반복문
// 각각 좌, 우, 하, 상
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// BFS 함수부분
int bfs(int x, int y) {

    queue<pair<int, int>> q;
    q.push({ x, y });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        
        // 상하좌우 모두 확인하는 반복문
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 벽에 부딪힌 경우
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            // 길이 아닌 경우
            if (graph[nx][ny] == 0) continue;
            
            // 길이 있으면서 처음 방문하는 경우
            if (graph[nx][ny] == 1) {
                
                // 직전까지 방문한 노드 수 + 1 저장
                graph[nx][ny] = graph[x][y] + 1;
                
                // 길이 있으니 다음 탐색을 위해 큐에 enqueue
                q.push({ nx, ny });
            }
        }
    }
    
    // 도착 부분인 좌표 (n, m) 의 노드 방문 횟수 리턴
    return graph[n - 1][m - 1];
}

int main() {
    
    // N, M 입력
    cin >> n >> m;
    
    // scanf를 활용하여 문자열에서 한 문자만 뽑아 graph에 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }
    
    // BFS 수행결과 출력
    cout << bfs(0, 0);

    return 0;
}