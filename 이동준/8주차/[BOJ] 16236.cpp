#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>
using namespace std;

//[BOJ] 16236. 아기 상어 / 골드 3 / 2시간
//개같이 복잡한 문제...
//매번 상어 위치에서 bfs 돌려서 가장 가까운곳에 있는 물고기 탐색

//상어 크기보다 작은 놈만 먹을수 있다
//상어 크기보다 작거나 같은 놈만 지나갈수 있다.
//처음 상어 크기는 2

//상어 크기 커지는건 물고기 수로 판단 (물고기 크기랑은 상관 x)
//상어 본인 크기와 동일한 마리수의 물고기를 먹어야 크기 1 증가

//못움직일때 까지 전체 움직인 거리를 리턴

int main() {
	int n; cin >> n;
	vector<vector<int>>v;
	pair<int, int>start;
	for (int i = 0; i < n; i++) {
		vector<int>t;
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp; 
			if (tmp == 9) {
				start.first = i;
				start.second = j;
				t.push_back(0);
			}
			else {
				t.push_back(tmp);
			}			
		}
		v.push_back(t);
	}
	
	pair<int, int> shark = make_pair(2, 0); //현재 크기, 먹은 물고기수 
	int ret = 0;
	//왼쪽 위부터 탐색할수 있게? 위부터 반시계?
	int x[4] = { 0,-1,0,1 };
	int y[4] = { -1,0,1,0 };

	while (true) {		
		vector<int>ttmp(n, -1);
		vector<vector<int>>visited(n, ttmp); //이거 빼먹지 말자
		visited[start.first][start.second] = 0;
		queue<pair<int, int>>q;
		q.push(start);
		int nowLen = 9999;
		set<pair<int, int>>hubo; //갈수 있는 후보지
		while (!q.empty()) {
			pair<int, int>now = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				pair<int, int>tmpNow = make_pair(now.first + y[i], now.second + x[i]);
				if (tmpNow.first >= 0 && tmpNow.first < n && tmpNow.second >= 0 && tmpNow.second < n) { //범위 벗어나는지
					if (v[tmpNow.first][tmpNow.second] <= shark.first && visited[tmpNow.first][tmpNow.second] == -1) { //지나갈수 있는 칸인지

						visited[tmpNow.first][tmpNow.second] = visited[now.first][now.second] + 1;
						q.push(make_pair(tmpNow.first, tmpNow.second));

						if (v[tmpNow.first][tmpNow.second] < shark.first && v[tmpNow.first][tmpNow.second]>0) { //먹을수 있는 놈인지

							//가장 가까운 모든 먹을수 있는놈을 저장해서 그중 가장 위 왼쪽에 있는곳으로 가야댐
							if (nowLen > visited[tmpNow.first][tmpNow.second]) {
								nowLen = visited[tmpNow.first][tmpNow.second];
							}

							if (nowLen == visited[tmpNow.first][tmpNow.second]) {
								hubo.insert(make_pair(tmpNow.first, tmpNow.second));
							}
							
						}

					}
				}
			}
		}

		if (nowLen == 9999) {
			break;
		}

		shark.second++;
		if (shark.first == shark.second) {
			shark.first++; shark.second = 0;
		}
		ret += nowLen;

		//시작위치 변경
		start.first = (*hubo.begin()).first;
		start.second = (*hubo.begin()).second;

		//먹은놈 지우기
		v[(*hubo.begin()).first][(*hubo.begin()).second] = 0;
		
	}	

	cout << ret;
}