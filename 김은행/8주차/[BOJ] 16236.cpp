#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int map[20][20];
bool visited[20][20];
int N;
int sX, sY, sSize = 2, sS;
int sec;

           // 상 좌 우 하
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };

void eat() {
    cout << "eat\n";

    sS++;

    if (sS == sSize) {
        sSize++;
        sS = 0;
    }
}

void clearVisited() {
    for (int j = 0; j < 20; j++) {
        for (int k = 0; k < 20; k++) {
            visited[j][k] = false;
        }
    }
}

void bfs() {
    queue<pair<int, int>> q;
    queue<int> dis;
    q.push(make_pair(sX, sY));
    
    int s = 0;
    dis.push(s);

    while (!q.empty()) {
        
        int _x = q.front().first;
        int _y = q.front().second;

        visited[_y][_x] = true;

        q.pop();
        for (int i = 0; i < 4; i++) {
            int _dx = _x + dx[i];
            int _dy = _y + dy[i];

            if (_dx < 0 || _dx > N - 1) continue;
            if (_dy < 0 || _dy > N - 1) continue;

            if (map[_dy][_dx] > sSize) continue;
            if (visited[_dy][_dx]) continue;

            if (map[_dy][_dx] == 0 || map[_dy][_dx] == sSize) {
                visited[_dy][_dx] = true;
                q.push(make_pair(_dx, _dy));
                dis.push(s+1);
                continue;
            }

            if (map[_dy][_dx] < sSize) {
                eat();
                sec += s;

                while (!q.empty()) q.pop(); // clear
                s = 0;
                sX = _dx;
                sY = _dy;
                clearVisited();

                q.push(make_pair(sX, sY));
                dis.push(s);
            }
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int objct;
            cin >> objct;
            
            if (objct == 9) {   // 아기 상어일 경우 좌표 저장
                sX = j;
                sY = i;

                continue;
            }

            map[i][j] = objct;
        }
    }

    bfs();

    cout << sec << endl;

    return 0;
}