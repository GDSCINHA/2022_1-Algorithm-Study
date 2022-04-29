#include <iostream>
#include <queue>
#include <utility>
using namespace std;

//[BOJ] 1463. 1로 만들기 / 실버 3 / 10분

int main() {
	int n, ret = 0; cin >> n;

	//bfs?
	queue<pair<int,int>>q;
	q.push(make_pair(n,0));
	while (!q.empty()) {
		pair<int,int> here = q.front(); q.pop();

		if (here.first == 1) {
			ret = here.second;
			break;
		}

		if (here.first % 3 == 0)
			q.push(make_pair(here.first / 3, here.second + 1));
		if (here.first % 2 == 0)
			q.push(make_pair(here.first / 2, here.second + 1));
		q.push(make_pair(here.first - 1, here.second + 1));
	}

	cout << ret;
}