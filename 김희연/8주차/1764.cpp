#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	set <string> setarr;
	vector <string> v1;
	vector <string> v2;
	vector <string> answer;
	string user;

	for (int i = 0; i < N; i++) {
		cin >> user;
		setarr.insert(user);
		v1.push_back(user);
	}
	for (int i = 0; i < M; i++) {
		cin >> user;
		setarr.insert(user);
		v1.push_back(user);
	}

	int s = setarr.size();
	for (int i = 0; i < s; i++) {
		v2.push_back(*setarr.begin());
		setarr.erase(setarr.begin());
	}

	sort(v2.begin(), v2.end());
	sort(v1.begin(), v1.end());
	set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(answer));
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}