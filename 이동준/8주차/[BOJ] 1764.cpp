#include <iostream>
#include <set>
#include <string>

using namespace std;

//[BOJ] 1764. 듣보잡 / 실버 4 / 5분

int main() {
	int n, m; cin >> n >> m;
	set<string> d;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		d.insert(s);
	}
	set<string>b;
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		if (d.find(s) != d.end()) {
			b.insert(s);
		}
	}
	cout << b.size() << "\n";
	for (auto i = b.begin(); i != b.end(); i++) {
		cout << *i << "\n";
	}
}