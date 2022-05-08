#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Chicken {
public:
	vector <vector<int>> minArr;
	vector <pair<int, int>> house;
	vector <pair<int, int>> chicken;
	int min = 2000, distance = 0, answer = 0;
	Chicken(int** arr, int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1) {
					house.push_back({ i, j });
				}
				else if (arr[i][j] == 2) {
					chicken.push_back({ i, j });
				}
			}
		}
		for (int i = 0; i < house.size(); i++) {
			min = 2000;
			for (int j = 0; j < chicken.size(); j++) {
				distance = (abs(house[i].first - chicken[j].first) +
					abs(house[i].second - chicken[j].second));
				cout << distance << " ";
				if (min > distance) {
					min = distance;
				}
				else {
					cout << "";
				}
				minArr.push_back(min);
			}
			cout << i << "번째 min은 " << min << endl;
			sort(minArr.begin(), minArr.end());
			answer += minArr[0];
			minArr.clear();
			cout << endl;
		}
		cout << endl;
		cout << "answer: " << answer << endl;
	}
};
int main() {
	int N, M;
	cin >> N >> M;

	int** city = new int* [N];
	for (int i = 0; i < N; i++) {
		city[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
		}
	}
	Chicken c(city, N, M);
}