#include <iostream>
#include <string>
using namespace std;

class C {
public:
	C(int n) {
		calculate(n);
	}
	int count = 0;

	void calculate(int n) {
		while (n != 1) {
			int what = n;
			what = (what - 1) / 3;
			if (n % 3 == 0) {
				n = n / 3;
				cout << n << " ";
			}
			else if (((n % 2) == 0) && (n - 1) % 3 != 0) {
				n = n / 2;
				cout << n << " ";
			}
			else if ((n % 2) == 0 && (what % 3 != 0)) {
				n = n / 2;
				cout << n << " ";
			}
			else {
				n = n - 1;
				cout << n << " ";
			}
			count++;
		}
		cout << endl;
		cout << count << endl;
	}
};

int main()
{
	int N, cow = 0;
	while (cow < 10) {
		cin >> N;
		C c(N);
		cow++;
	}
}