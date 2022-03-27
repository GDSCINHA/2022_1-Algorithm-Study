
 #include <iostream>
#include <vector>
using namespace std;

class Exploration {
public:
	Exploration() {};
	vector<vector<int>> v;
	vector <int> v2;
	v.push_back(v2);

	int i = 0, j = 0, count = 0;
	void fx(int _N, int _M) {
		if (v[i + 1][j] == 0 && v[i][j + 1] == 1) {
			fx(i, j + 1);
			nCount();
		}
		else if (i == _N && j != _M) {
			fx(i, j + 1);
			nCount();
		}
		if (v[i + 1][j] == 1 && v[i][j + 1] == 0) {
			fx(i + 1, j);
			nCount();
		}
		else if (j == _M && i != _N) {
			fx(i + 1, j);
			nCount();
		}
		if (v[i + 1][j] == 1 && v[i][j + 1] == 1) {
			fx(i + 1, j);
			nCount();
		}
		if (i == _N && j == _M) {
			cout << count;
		}
	}
	void nCount() {
		count++;
	}
};
int main()
{
	Exploration e;
	int N, M;
	cin >> N >> M;
	e.v(N, vector<int>(M, 0));
	char* arr = new char[M];
	e.v.push_back(e.v2);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[j];
		}
		for (int j = 0; j < M; j++) {
			e.v[i].push_back((arr[j] - '0'));
		}
	}
	e.v.push_back(e.v2);
	cout << "--------" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[j];
		}
		cout << endl;
	}
	e.fx(0, 0);

	return 0;
}