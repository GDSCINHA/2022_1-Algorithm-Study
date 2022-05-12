#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

//[BOJ] 1967. 트리의 지름 / 골드 4 / 15분

int main() {
	//트리의 지름 구하는 방법
	
	//아무점에서 시작해서 가장 먼 노드 찾기
	//거기서 한번더 가장먼 노드 찾기

	int n, ret = 0; cin >> n;
	vector<pair<int, int>>tmp;
	vector<vector<pair<int, int>>>g(n + 1, tmp);
	for (int i = 0; i < n; i++) {
		int p, c, w;
		cin >> p >> c >> w;
		g[p].push_back(make_pair(c, w));
		g[c].push_back(make_pair(p, w));
	}

	queue<int>q;
	vector<int>visited(n + 1, -1);
	q.push(1); visited[1] = 0;
	while (!q.empty()) {
		int here = q.front(); q.pop();
		for (int i = 0; i < g[here].size(); i++) {
			if (visited[g[here][i].first] == -1) {
				visited[g[here][i].first] = visited[here] + g[here][i].second;
				q.push(g[here][i].first);
			}
		}
	}
	int far;
	for (int i = 1; i < visited.size(); i++) {
		if (ret < visited[i]) {
			ret = visited[i];
			far = i;
		}
	}

	visited.assign(n + 1, -1);
	q.push(far); visited[far] = 0;
	while (!q.empty()) {
		int here = q.front(); q.pop();
		for (int i = 0; i < g[here].size(); i++) {
			if (visited[g[here][i].first] == -1) {
				visited[g[here][i].first] = visited[here] + g[here][i].second;
				q.push(g[here][i].first);
			}
		}
	}
	ret = 0;
	for (int i = 1; i < visited.size(); i++) {
		if (ret < visited[i]) {
			ret = visited[i];
		}
	}

	cout << ret;
}