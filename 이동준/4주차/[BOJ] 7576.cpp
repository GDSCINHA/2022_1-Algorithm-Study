#include <iostream>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
// [BOJ] / 7576. 토마토 / 골드 5 / 30분
int main() {
	int m, n; cin >> m >> n;

	vector<vector<int>>box;
	for (int i = 0; i < n; i++) {
		vector<int>tmp;
		for (int j = 0; j < m; j++) {
			int ttmp; cin >> ttmp; tmp.push_back(ttmp);
		}
		box.push_back(tmp);
	}
	
	//상우하좌
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	
	//bfs 토마토 위치 먼저 큐에 다 넣기, 방문 여부는 0으로 구분, 방문칸은 일수 저장
	queue<pair<int,int>>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 1) {
				q.push(make_pair(i,j));
			}
		}
	}

	while (!q.empty()) {
		pair<int, int>here = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = here.first + dx[i], y = here.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m) {
				if (box[x][y] == 0) {
					box[x][y] = box[here.first][here.second] + 1;
					q.push(make_pair(x, y));
				}
			}
		}
	}

	//정답 찾기
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				ret = -1;
				break;
			}
			else {
				if (box[i][j] > ret)
					ret = box[i][j];
			}
		}
		if (ret == -1)
			break;
	}

	if (ret == -1)
		cout << ret;
	else
		cout << ret - 1;
}