#include <iostream>

using namespace std;

int stick[100001];          // 최대 범위인 100,000
int cnt;                    // 보이는 막대기 개수 변수

int main() {
	int N, n;               // 총 막대기의 개수 변수

	cin >> N;               // 총 막대기의 개수 변수 할당


    // 막대기의 개수만큼 stick 배열에 높이인 h 저장
	for (int i = 0; i < N; i++) {
		int h;
		cin >> h;
		stick[i] = h;
	}


    // 다음 반복문을 수행하기 위해 맨 뒤의 막대기 값을 current에 저장
	int current = stick[N - 1];

    // 막대기의 개수만큼 반복문 수행을 위해 n 할당
	n = N - 1;
    
    // 막대기의 개수를 세는 반복문
	while (n--) {
		if (stick[n] > current) {
			current = stick[n];     // 앞의 막대기보다 높을 경우에
			cnt++;                  // current 재할당
		}
	}

	cout << ++cnt;          // 한개는 무조건 보이기 때문에 +1

	return 0;
}