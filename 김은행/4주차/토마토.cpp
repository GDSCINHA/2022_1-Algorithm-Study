#include <iostream>
#include <queue>

using namespace std;

// 우,하,좌,상
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m, ans;
int box[1001][1001];

queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 상자를 벗어나는 경우
            if (0 > nx || 0 > ny || nx >= m || ny >= n)
                continue;

            // 익지 않은 토마토인 경우
            if (box[ny][nx] == 0) {
                box[ny][nx] = box[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int main() {

    cin >> m >> n;
    
    // 모든 익은 토마토 주소를 'q'에 enqueue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    
    // bfs 실행
    bfs();
    
    // bfs 실행 결과를 바탕으로 일수 산정
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            // 익지않은 토마토 발견시 '-1' 출력 후 종료
            if (box[i][j] == 0) {
                cout << "-1\n";
                return 0;
            }
            
            // 최소 일수 산정
            if (ans < box[i][j]) {
                ans = box[i][j];
            }
        }
    }

    cout << ans - 1 << "\n";

    return 0;
}