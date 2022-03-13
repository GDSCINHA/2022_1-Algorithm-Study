#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int cur, ans;

int main() {
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> v(N);

	// 입력
	for (int i = 0; i < N; i++)
		scanf("%d %d", &v[i].second, &v[i].first);

	// 정렬
	sort(v.begin(), v.end());

    // 연산 수행
	for (int i = 0; i < N; i++) {
		if (cur <= v[i].second) {
			cur = v[i].first;
			ans++;
		}
	}

	printf("%d", ans);

	return 0;
}