// [BOJ] / 1347. 미로 만들기 / 실버 4 / 35분
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	char miro[102][102];
	memset(miro, '#', sizeof(miro));

	int x1 = 50, x2 = 50, y1 = 50, y2 = 50; //왼쪽 위 좌표, 오른쪽 밑 좌표
	int dir = 0, x = 50, y = 50;
	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { 1,0,-1,0 };

	miro[x][y] = '.';
	for (int i = 0; i < n; i++) {
		if (s[i] == 'F') {
			x = x + dx[dir];
			y = y + dy[dir];

			miro[x][y] = '.';

			if (x1 > x) {
				x1 = x;
			}
			if (y1 > y) {
				y1 = y;
			}
			if (x2 < x) {
				x2 = x;
			}
			if (y2 < y) {
				y2 = y;
			}
		}
		if (s[i] == 'R') {
			dir = (dir + 1) % 4;
		}
		if (s[i] == 'L') {
			dir = (dir - 1 + 4) % 4;
		}
	}

	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			cout << miro[j][i];
		}
		cout << "\n";
	}

}