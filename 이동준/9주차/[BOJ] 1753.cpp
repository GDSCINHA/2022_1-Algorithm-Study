#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

// [BOJ] / 1753. 최단경로 / 골드 5 / 1시간 답지 참고

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, k; cin >> v >> e >> k;
	vector<pair<int, int>>tmp;
	vector<vector<pair<int, int>>>ad(v + 1, tmp);
	for (int i = 0; i < e; i++) {
		int U, V, W; cin >> U >> V >> W;
		ad[U].push_back(make_pair(V, W));
	}

	//다익스트라.. 알고리즘 강의때 배웠는데 기억 안나서 좀 찾아봄
	//mst = 프림(노드기준), 크루스칼(엣지기준)
	//single source shortest path = 다익스트라
	//all pair shortest path = 플로이드 와샬 (transitive closure 뭐라하지 도달 가능한 노드면 한번에 가는 엣지를 추가 하는것)에서 약간 추가

	vector<int>ret(v + 1, INT_MAX);
	priority_queue<pair<int, int>>q; q.push(make_pair(0, k)); ret[k] = 0;
	//큐 first는 -붙인 거리(기본적으로 내림차순 정렬이어서), second는 노드번호 
	while (!q.empty()) {
		int here = q.top().second;
		int dist = -q.top().first;
		q.pop();
		for (int i = 0; i < ad[here].size(); i++) {
			int next = ad[here][i].first;
			int nextDist = ad[here][i].second;
			if (dist + nextDist < ret[next]) {
				ret[next] = dist + nextDist;
				q.push(make_pair(-ret[next], next));
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (ret[i] == INT_MAX) {
			cout << "INF\n";
		}
		else {
			cout << ret[i] << "\n";
		}
	}

}