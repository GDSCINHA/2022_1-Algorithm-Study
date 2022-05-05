#include <iostream>
using namespace std;

//[BOJ] 10870. 피보나치 수 5 / 브론즈 2 / 2분

int fib(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

int main() {
	int n; cin >> n;
	cout << fib(n);
}