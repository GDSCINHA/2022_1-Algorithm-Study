#include <iostream>
using namespace std;

class Fibonacci {
public:
	int i = 0, oldn = 0, n = 0;
	int answer;
	void recursive(int num, int count) {
		if(count != 0) {
			n = oldn + num;
			oldn = num;
			recursive(n, count - 1);
		}
		answer = n;
	}
	void print() {
		cout << answer << endl;
	}
};

int main() {
	int N;
	cin >> N;
	Fibonacci f;
	if (N == 1) {
		cout << 1 << endl;
	}
	else if (N == 0) {
		cout << 0 << endl;
	}
	else {
		f.recursive(1, N-1);
		f.print();
	}
}