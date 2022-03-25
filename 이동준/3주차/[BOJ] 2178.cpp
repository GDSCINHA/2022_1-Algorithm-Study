// [BOJ] / 2178. 미로 탐색 / 실버 1 / 30분
#include <iostream>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int miro[102][102];
	bool visited[102][102];
	memset(miro, -1, sizeof(miro));
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//i가 y j가 x
			char a;
			cin >> a;
			miro[i][j] = a - '0';
		}
	}

	//bfs
	queue<pair<int,int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	while (!q.empty()) {
		pair<int, int>here = q.front();
		if (here.first == n && here.second == m) {
			break;
		}
		q.pop();
		
		int dx[4] = { -1,0,1,0 };
		int dy[4] = { 0,1,0,-1 };

		//상좌하우 방문
		for (int i = 0; i < 4; i++) {
			int herex = here.first + dx[i];
			int herey = here.second + dy[i];
			if (herex >= 0 && herex <= n && herey >= 0 && herey <= m) {
				if (!visited[herex][herey]&&miro[herex][herey]>0) {
					visited[herex][herey] = true;
					q.push(make_pair(herex, herey));
					miro[herex][herey] = miro[here.first][here.second] + 1;
				}
			}
		}	
	}
	cout << miro[n - 1][m - 1];

}