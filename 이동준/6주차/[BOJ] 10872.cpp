#include <iostream>
using namespace std;

//[BOJ] 10872. 팩토리얼 / 브론즈 3 / 5분

int fac(int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	return fac(n - 1) * n;
}

int main() {
	int n; cin >> n;
	cout << fac(n);
}