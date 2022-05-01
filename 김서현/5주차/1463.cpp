//bottom-up? dp? 모르겠다
//https://sectumsempra.tistory.com/84
#include <iostream>
using namespace std;
int arr[1000001];
int n = 0;

int number(int x)
{
	if (x == 1) {
		return 0;
	}
	if (arr[x] != 0) {
		return arr[x];
	}

	int res = 1 + number(x - 1); // -1
	if (x % 3 == 0)res = min(res, 1 + number(x / 3)); // %3
	if (x % 2 == 0)res = min(res, 1 + number(x / 2));// %2
	arr[x] = res;
	return res;
}
int main() {
	//c stdio와 cpp iostream을 동기화 비활성화
	ios::sync_with_stdio(false);

	//cin과 cout의 묶음을 풀어줌->순서가 사라짐
	cin.tie(0);
	
	//여기 이해가 안감
	arr[2] = 1;
	arr[3] = 1;
	cin >> n;

	cout << number(n);

	return 0;
}