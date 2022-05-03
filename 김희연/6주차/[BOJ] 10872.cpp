#include <iostream>
using namespace std;

class Factorial {
public:
	int n, answer, oldn = 0;
	void recursive(int num) {
		if (num == 1) {
			answer = num;
			return;
		}
		if (oldn == 0) {
			n = num * (num - 1);
			oldn = n;
			recursive(num - 1);
		}
		else {
			n = (num - 1) * oldn;
			oldn = n;
			recursive(num - 1);
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
	Factorial f;
	if (N == 0) {
		cout << 1 << endl;
	}
	else {
		f.recursive(N);
		f.print();
	}
}