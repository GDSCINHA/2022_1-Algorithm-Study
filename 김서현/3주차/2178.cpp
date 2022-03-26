//[BOJ] / 2178. 미로탐 색 / 실버 1 / 1시간

#include <iostream>
using namespace std;

int main() {
	int count = 0;
	int n = 0;
	int m = 0;


	cin >> n >> m;

	int maze[100][100];

	//미로 입력
	for (int i = 0; i < n; i++) {
		string mz;
		cin >> mz;
		for (int j = 0; j < m; j++) {
			maze[i][j] = mz[j] - '0';
		}
	}

	//1이면 가고 0이면 못감
	//아 진짜 모르겠어요 아나 뭐지
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i + 1][j] == 1) {
				i++;
				count++;
			}

			else if (maze[i][j + 1] == 1) {
				i++;
				count++;
			}

			else if (maze[i + 1][j] == 0 && maze[i][j + 1] == 0) {
				break;
			}
		}
	}
	cout << count;
}